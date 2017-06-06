var openD = false;
var animateOpen = false;
var animateClose = false;
var timer = 0;
function drawDoor(){
	fill("#322617");
	quad(275-timer*1.2, 500, 276-timer*1.3, 427, 238, 423, 240, 492);

	fill(0);
	var width = 2-timer/10;
	if(width < 0)
		width = 0;
	ellipse(270-timer, 464, width, 3);
	if(animateOpen){
		if(timer >= 50)
		{
			animateOpen = false;
			animateClose = false;
			openD = true;
		}else timer++;
		
	}else if (animateClose)
	{
		if(timer <= 0)
		{
			animateOpen = false;
			animateClose = false;
			openD = false;
		}else
		timer--;
	}
}