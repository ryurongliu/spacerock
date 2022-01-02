inlets = 1;
outlets = 0;


//on bang, create messages and sel box to do stuff etc. 

function name(filename)
{
	innie = this.patcher.getnamed("in_start");
	
	in_delay = this.patcher.getnamed("in_delay"); 
	
	trigger = this.patcher.newdefault(10, 120, "t b b");
	
	selector = this.patcher.getnamed("selector");
	
	gate = this.patcher.getnamed("gate");
	
	in4 = this.patcher.getnamed("in4");

	trig0 = this.patcher.newobject("message", 40, 150, 10, 10, 0);
	
	counter = this.patcher.newdefault(10,180, "counter");
	
	outie = this.patcher.getnamed("out1");
	
	this.patcher.connect(selector, 1, trigger, 0); 
	this.patcher.connect(trigger, 1, trig0, 0);
	
	this.patcher.connect(trigger, 0, counter, 0);
	this.patcher.connect(trig0, 0, counter, 3); 
	this.patcher.connect(in4, 0, trig0, 0); 
	this.patcher.connect(gate, 0, counter, 0);
	
	var f = new File(filename);
	var csv = [];
	var seq = [];
	var i = 0;
	while(f.position<f.eof){
		var str = f.readline();
		var info = str.split(" "); 
		var chord = parseInt(info[0]);
		var dur = parseFloat(info[1]); 
		var mes = this.patcher.newobject("message", (10 + i*50), 300, 20, 10, chord, dur);
		seq.push(mes); 
		i+=1;
	}
	f.close();
	
	var sel_str = "sel";
	var j = 0;
	while( j<i){
		sel_str += " " + String(j+1);
		j+= 1;
	}
	
	var sel = this.patcher.newdefault(10, 220, sel_str);
	
	this.patcher.connect(counter, 0, sel, 0); 
	
	var j = 0;
	while(j < i){
		this.patcher.connect(sel, j, seq[j], 0);
		this.patcher.connect(seq[j], 0, outie, 0);
		j+=1;
	}
	
	
	out2 = this.patcher.getnamed("out2");
	this.patcher.connect(sel, i, out2, 0);
}

function reset()
{
	var num_obj = this.patcher.count; 
	ob = this.patcher.firstobject; 
	
	var i = 0;
	while(i < num_obj){
		
		nextob = ob.nextobject; 
		if (ob.varname=="")
			this.patcher.remove(ob);
		
		ob = nextob;
		
		i+= 1;
		
	}
	
}