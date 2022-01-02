//pick note from 0-15

inlets = 1;
outlets = 1;

keys = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];

function msg_int(i)
{
	var index = keys.indexOf(i);
	
	outlet(0, index);
}