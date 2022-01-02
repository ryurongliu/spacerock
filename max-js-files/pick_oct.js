//select octave from 0-7

inlets = 2;
outlets = 1;

oct = 4;

akey = this.patcher.getnamed("akey");
post(akey.bgfillcolor.value);
function bang()
{
	if (inlet==0 && oct > 0) //DOWN oct
	{
		oct -= 1;
	}
	if (inlet==1 && oct < 7)
	{
		oct += 1;
	}
	outlet(0, oct);
}