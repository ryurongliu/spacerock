inlets = 1;
outlets = 0;

function name(filename){
	
	gate = this.patcher.getnamed("gate");
	out1 = this.patcher.getnamed("out1");
	out2 = this.patcher.getnamed("out2");
	
	
	var f = new File(filename);
	var seq = [];
	var i = 0;
	while(f.position<f.eof){
		var str = f.readline();
		var info = str.split(" ");
		var oct =parseInt(info[0]);
		var note = parseInt(info[1]);
		var dur = parseFloat(info[2]);
		var mes = this.patcher.newobject("message", 10+(i*50), 600, 20, 10, oct, note, dur);
		seq.push(mes);
		i+= 1;
	}
	f.close();
	
	var sel_str = "sel";
	var j = 0;
	while(j<i){
		sel_str += " " + String(j+1);
		j+=1;
	}
	
	var sel = this.patcher.newdefault(10, 500, sel_str);
	
 	this.patcher.connect(gate, 0, sel, 0);

	var j = 0; 
	while(j < i ){
		this.patcher.connect(sel, j, seq[j], 0);
		this.patcher.connect(seq[j], 0, out1, 0);
		j+=1;
	}
	
	this.patcher.connect(sel, i, out2, 0);
	
}

function reset(){
	var num_ob = this.patcher.count;
	ob = this.patcher.firstobject;
	var i = 0;
	while(i < num_ob){
		nextob = ob.nextobject;
		if (ob.varname==""){
			this.patcher.remove(ob);
		}
		ob = nextob; 
		i+= 1;
	}
}