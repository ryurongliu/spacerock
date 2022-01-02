inlets = 1;
outlets = 2;

function name(filename){
	
	var f = new File(filename);
	var waitdur = 0;
	var ondur = 0;
	while(f.position<f.eof){
		var str = f.readline();
		var info = str.split(" ");
		ondur = parseFloat(info[0]);
		waitdur = parseFloat(info[1]);
	}
	outlet(0, ondur);
	outlet(1, waitdur); 
	
}