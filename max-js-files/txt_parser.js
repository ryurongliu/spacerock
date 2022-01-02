inlets = 1;
outlets = 16;

//separates into CHORDS

function name(filename)
{

	var f = new File(filename); 
	var csv = [];
	while(f.position<f.eof){
		var str = f.readline();
		csv.push(str);
	}
	f.close();
	for (var i=0; i<csv.length; i++){ //loop over CHORD
		outlet(i, csv[i]);
		
	}
}