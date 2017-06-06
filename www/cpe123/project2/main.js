var movePerson = false;
var moveDist = 0;
var clickCount = 0;
var appleSwap = false;
function setup(){
	createCanvas(1200, 800);
}
function draw(){
	strokeWeight(0);
	background("#02880B");
		sky();
	leftSide();
	if(noClick)
	{
		runNoClick();
	}else{
		holeLeftSide("#362F23");
		scissors();
		holeRightSide("#027809");
	}
	rightSide();
	frontPorch();
	drawDoor();
	if(movePerson && moveDist < 60)
		moveDist++;
	drawPerson(500 + moveDist*.8, 200 - moveDist/3 - moveDist/25, .07);
	if(noClick)
		personCover(true);
	else
		personCover(false);
	if(fall)
	{
		console.log("animate head");
		if(!appleSwap)
			animateHead(500 + moveDist*.8, 200 - moveDist/3 - moveDist/25, .07);
		else drawApple(466, 698, .15);
	}
	
}
function mouseReleased()
{
	console.log(mouseX + ", " + mouseY);
	clickCount++;
	if(clickCount > 1 && movePerson)
		noClick =  false;
	if(!animateOpen && !openD && mouseX > 238 && mouseX < 276 && mouseY < 497 && mouseY > 425)
		animateOpen = true;
	if(openD && mouseX > 212 && mouseX < 276 && mouseY < 497 && mouseY > 425)
		animateClose = true;
	console.log(noClick);
	if(!noClick)
	{
		if (mouseX > 404 && mouseX < 423
			&& mouseY > 481 && mouseY < 500) {
			if(!swap)
				swap = true;
			else if(!fall) fall = true;
		}
	}
	if(fall){
		if(mouseY > 689 && mouseY < 716 && mouseX > 456 && mouseX < 482)
			appleSwap = true;
	}
	if(mouseX > 393 && mouseX < 432 && mouseY > 435 && mouseY < 499)
		movePerson = true;
	
	console.log(mouseX + ", " + mouseY)
}