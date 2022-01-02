inlets = 1;
outlets = 14; //OCT and NOTE output for each note, maximum 7 to a chord

//turns CHORD line into OCT and NOTE output

function oct_notes(i){
	
	var encoded = String(i).split(" ");
	var num_notes = encoded.length/2;
	for (j=0; j<num_notes; j++)
	{
		outlet(2*j, parseInt(encoded[2*j]));
		outlet(2*j+1, parseInt(encoded[2*j+1])); 
	}
	
	
}