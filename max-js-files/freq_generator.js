inlets = 1; //left inlet for OCTAVE[0-7], right inlet for NOTE[0-15]
outlets = 1;

var autowatch = 1;

var periods = [4.61, 4.62, 4.36, 3.63, 4.13, 3.78, 3.68, 3.27, 3.69, 5.57, 3.84, 3.56, 4.14, 4.16, 4.3, 4.99, 6.54];

var cents = [0, 66.67, 133.33, 200, 266.67, 333.33, 400, 533.33, 600, 666.67, 733.33, 800, 866.67, 933.33, 1000, 1066.67];

var octave = null; 
var note = null; 



function list() {
	octave = Number(arguments[1]); 
	note = arguments[0]; 
	var basefreq = 27.5 * Math.pow(2, octave);
	var newfreq = basefreq * Math.pow(2, cents[note]/1200);
	outlet(0, newfreq);
}

	