var swap = false;
var headX = 0;
var headY = 0;
var clockX = 0;
var clockY = 0;

var rotX = 0;

var fall = false;
var headY1 = 0;
var headX1 = 0;
function personCover(houseView){
	fill("#871910");
	push();
	scale(2, .5);
	translate(-200, 565);
	quad(393, 434, 435, 440, 434, 518, 393, 501);
	pop();
	push();
	if(houseView)
	{
	translate(-477, 0);
	scale(2, 1);
	}else{
		translate(285, 0);
		scale(.25, 1);
	}
	quad(393, 434, 435, 440, 434, 518, 393, 501);
	pop();
	
}
function drawPerson(x, y, s){
	push();
	rotate(PI/6);
	translate(x, y);
	scale(s);
	noStroke();
	fill(196, 196, 196);
	beginShape();
	vertex(430, 355);
	vertex(720, 336);
	vertex(720, 336);
	curveVertex(720, 336);
	curveVertex(769, 351);
	curveVertex(802, 373);
	curveVertex(815, 396);
	curveVertex(821, 443);
	vertex(821, 443);
	vertex(821, 443);
	vertex(821, 443);
	vertex(821, 800);
	vertex(821, 800);
	vertex(398, 800);
	vertex(398, 800);
	vertex(393, 677);
	vertex(393, 677);
	vertex(393, 677);
	vertex(219, 664);
	vertex(219, 664);
	vertex(219, 664);
	vertex(219, 664);
	curveVertex(219, 664);
	curveVertex(206, 658);
	curveVertex(195, 642);
	curveVertex(194, 606);
	curveVertex(200, 595);
	vertex(200, 595);
	vertex(376, 352);
	vertex(376, 352);
	endShape();

	//left arm lines
	fill(0);
	stroke(0);
	strokeWeight(2);
	line(417, 467, 378, 575);
	line(325, 575, 400, 575);
	line(393, 677, 400, 575);

	//left hand
	fill(255, 212, 186);
	noStroke();
	beginShape();
	vertex(400, 585);
	vertex(400, 585);
	vertex(502, 585);
	vertex(511, 656);
	vertex(511, 656);
	curveVertex(511, 656);
	curveVertex(497, 669);
	curveVertex(470, 673);
	vertex(470, 673);
	vertex(470, 673);
	vertex(395, 669);
	vertex(400, 585);
	endShape();

	//left thumb
	beginShape();
	vertex(385, 585);
	vertex(450, 537);
	vertex(450, 537);
	curveVertex(450, 537);
	curveVertex(458, 534);
	curveVertex(465, 537);
	vertex(465, 537);
	vertex(465, 537);
	vertex(450, 585);
	vertex(415, 585);
	vertex(385, 585);
	endShape();

	//left finger
	//GOOD EXAMPLE OF curveVertex!!!!!!!!!!!!!
	beginShape();
	vertex(485, 580);
	curveVertex(520, 580);
	curveVertex(520, 580);
	curveVertex(588, 590);
	curveVertex(588, 610);
	curveVertex(530, 610);
	curveVertex(520, 610);
	vertex(485, 610);
	vertex(485, 610);
	vertex(485, 580);
	vertex(485, 580);
	endShape();

	//shirt
	fill(215, 184, 224);
	beginShape();
	vertex(508, 347);
	vertex(675, 339);
	vertex(588, 573);
	endShape();

	//tie;
	fill(28, 48, 119);
	beginShape();
	vertex(570, 343);
	vertex(603, 342);
	vertex(620, 487);
	vertex(588, 573);
	vertex(559, 487);
	endShape();
if(!fall)
{
push();
	translate(headX + headX1, headY + headY1);
//	rotate(rotX);

	//head
	fill(255, 212, 186);
	ellipse(586, 245, 240, 240);

	//lips
	fill(204, 114, 114);
	rect(546, 299, 80, 10);

	//left eye
	fill(255);
	ellipse(555, 236, 50, 20);
	fill(0);
	ellipse(555, 236, 20, 20);

	//right eye
	fill(255);
	ellipse(620, 236, 50, 20);
	fill(0);
	ellipse(620, 236, 20, 20);
pop();
}
push();
	translate(clockX, clockY);

	//clock frame
	stroke(165, 165, 165);
	fill(255);
	strokeWeight(20)
	ellipse(780, 560, 290, 290);

	//numbers
	fill(0);
	strokeWeight(0);
	stroke(255);
	textSize(40);
	text("12", 760, 435, 40, 40);
	text("1", 825, 445, 40, 40);
	text("2", 865, 485, 40, 40);
	text("3", 880, 540, 40, 40);
	text("4", 865, 595, 40, 40);
	text("5", 825, 635, 40, 40);
	text("6", 770, 645, 40, 40);
	text("7", 720, 635, 40, 40);
	text("8", 680, 595, 40, 40);
	text("9", 660, 540, 40, 40);
	text("10", 665, 485, 40, 40);
	text("11", 705, 445, 40, 40);

	//center
	fill(0);
	ellipse(780, 560, 15, 15);

	//clock hands
	strokeWeight(7);
	stroke(0);
	line(771, 575, 820, 490);
	strokeWeight(4);
	line(759, 546, 870, 620);
pop();

	//if swap is true (when mouse is clicked the first time)
	//then the head is translated to the spot of the clock
	//and the clock is translated to the spot of the head
	if (swap) {
		headY = 300;
		headX = 200;
		clockX = -200;
		clockY = -320;
	}

	// after the swap, if fall is true (when mouse is clicked
	// the second time), then while
	// headY < bottom of the screen,
	pop();
}
var headTimer = 0;
var headScaler = 1;
function animateHead(x, y, s){
push();
	rotate(PI/6);
	translate(x, y);
	scale(s);
	noStroke();
	fill(196, 196, 196);
	headTimer++;
	if (headTimer < 20) {
		headY1 += 50;
		headX1 += 35;
	}else if(headTimer <=25)
	{
		headY1 -= 3;
		headX1 += 10;
	}else if (headTimer < 45) {
		headY1 += 40;
		headX1 += 40;
	}else if(headTimer <=50)
	{
		headY1 -= 3;
		headX1 += 10;
	}
	else if (headTimer < 70) {
		headY1 += 30;
		headX1 += 30;
	}else if(headTimer <=75)
	{
		headY1 -= 3;
		headX1 += 10;
	}
	
	/*else if (headY1 >= 100) {
		headX1 = headX1 + 1;
		rotX = rotX + (PI/180);
	}*/
	push();
		translate(headX + headX1, headY + headY1);
	//	rotate(rotX);

		//head
		fill(255, 212, 186);
		ellipse(586, 245, 240, 240);

		//lips
		fill(204, 114, 114);
		rect(546, 299, 80, 10);

		//left eye
		fill(255);
		ellipse(555, 236, 50, 20);
		fill(0);
		ellipse(555, 236, 20, 20);

		//right eye
		fill(255);
		ellipse(620, 236, 50, 20);
		fill(0);
		ellipse(620, 236, 20, 20);
	pop();
pop();
}