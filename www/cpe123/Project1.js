//Aleksandr Vetushko
//Julian Tan


var scaleMicro = 1;
var xMicro = 300;
var yMicro = 634;
var xfingers = 0;
var goingForward = true;
var yHead = 0;

function drawMicroscope(speed) {
		/* microscope */
	push();
		translate(xMicro, yMicro);
		scale(scaleMicro);
		fill(purple);
		quad(-4, -209, -32, -198, -39, -218.5, -13, -229);//eye piece
		fill(blue);
		beginShape();
		curveVertex(-15, -154);
		curveVertex(-15, -154);
		curveVertex(-85, -107);
		curveVertex(-111, -69);
		curveVertex(-117, -31);
		curveVertex(-111, 1);
		curveVertex(-111, 1);
		endShape();

		quad(-16, -154, -6, -105, -56, 0, -111, 0);

		push();
			fill(255);
			beginShape();
			curveVertex(-5.5, -105);
			curveVertex(-5.5, -105);
			curveVertex(-51, -70);
			curveVertex(-64, -34);
			curveVertex(-55, 0);
			curveVertex(-55, 0);
			endShape();
		pop();

		quad(2, -215, 97, 0, 31, 0, -39, -199); //long part of scope
		fill(143, 116, 196); //purple
		ellipse(16, -71, 58, 58); //zoom wheel
	pop();
	if(xMicro < 786){
	xMicro += speed;
	}
}

function drawHand(speed) {
		push();
		translate(xfingers, 0);
				beginShape();
				curveVertex(251, 654);
				curveVertex(231, 634);
				curveVertex(316, 577);
				curveVertex(350, 577);
				endShape();
				beginShape(); //fingers
				curveVertex(316, 577);
				curveVertex(370, 578);
				curveVertex(404, 591);
				curveVertex(397, 600);
				curveVertex(372, 596);
				curveVertex(361, 597);
				endShape();
				quad(316, 577, 370.5, 578, 372.5, 596, 317, 595);
				beginShape();
				curveVertex(300, 609);
				curveVertex(315, 609);
				curveVertex(363, 612);
				curveVertex(416, 627);
				curveVertex(418, 634);
				endShape();
				beginShape();
				curveVertex(411, 622);
				curveVertex(415.5, 626.5);
				curveVertex(418, 632);
				curveVertex(418, 634);
				curveVertex(418, 640);
				endShape();
				beginShape();
				curveVertex(320, 600);
				curveVertex(325, 620);
				curveVertex(330, 638);
				curveVertex(335, 634);
				curveVertex(348, 630);
				curveVertex(377, 634);
				curveVertex(382, 638);
				curveVertex(387, 620);
				curveVertex(392, 600);
				endShape();
				beginShape();
				curveVertex(320, 580);
				curveVertex(327, 582);
				curveVertex(340, 587);
				curveVertex(337, 597);
				curveVertex(332, 600);
				curveVertex(331, 603);
				curveVertex(332, 606);
				curveVertex(337, 609);
				curveVertex(340, 619);
				curveVertex(327, 624);
				curveVertex(320, 626);
				endShape();
				quad(230.5, 634, 315.5, 577, 330, 592, 329, 634);
				beginShape();
				vertex(330, 610);
				vertex(416, 627);
				vertex(418, 634);
				vertex(383, 634);
				vertex(335, 630);
				endShape();
				triangle(328, 600, 336, 591, 357, 593);
				triangle(330, 607, 359, 611, 342, 618);

										if (xfingers < 486 && goingForward) {
											xfingers += speed;
										}
										else if (xfingers > 0 && !goingForward) {
											xfingers -= speed;
										}
										else if (xfingers == 486 && goingForward) {
											goingForward = false;
										}
		pop();
	pop();
}

function drawHead(speed) {
	push();
		translate(0, yHead);
			//head
			fill(242, 123, 99);
			arc(240,339,58,70,3*PI/2,PI/2);

			//ear
			fill(242, 123, 99);
			beginShape();
			vertex(266, 352);
			vertex(266, 352);
			curveVertex(270, 348);
			curveVertex(272, 340);
			vertex(269, 340);
			vertex(269, 340);
			vertex(266, 352);
			endShape();

			//hair
			beginShape();
			fill(76, 48, 41);
			noStroke();
			vertex(240, 300);
			vertex(263, 316);
			vertex(263, 316);
			curveVertex(263, 316);
			curveVertex(254, 320);
			curveVertex(244, 320);
			curveVertex(240, 319);
			vertex(240, 319);
			vertex(240, 319);
			vertex(240, 300);
			vertex(240, 300);
			endShape();

			//eye
			fill(76, 48, 41);
			noStroke();
			ellipse(252, 338, 4);
			endShape();

			//eyebrow
			fill(76, 48, 41);
			stroke(76, 48, 41);
			beginShape();
			vertex(251, 331)
			curveVertex(251, 331);
			curveVertex(253, 333);
			curveVertex(256, 335);
			curveVertex(258, 336);
			vertex(258, 336);
			endShape();

			//nose
			noFill();
			stroke(76, 48, 41);
			beginShape();
			curveVertex(240, 342);
			curveVertex(241, 342);
			curveVertex(243, 343);
			curveVertex(244, 345);
			curveVertex(243, 347);
			curveVertex(241, 348);
			curveVertex(240, 348);
			endShape();

			//dimple
			fill(76, 48, 41);
			stroke(76, 48, 41);
			beginShape();
			vertex(245, 349);
			vertex(254, 364);
			vertex(250, 369);
			vertex(254, 364);
			endShape();

			//mouth
			fill(76, 48, 41);
			stroke(76, 48, 41);
			curve(226, 356, 241, 358,
				248, 364, 255, 378);

			//hat
			beginShape();
			fill(119, 173, 206);
			noStroke();
			vertex(240, 300);
			vertex(262, 317);
			vertex(271, 306);
			vertex(249, 288);
			vertex(240, 300);
			endShape();
			if (xMicro == 786 && yHead < 43) {
				yHead += speed;
			}
	pop();
}

function setup() {
	createCanvas(1000, 634);
}

function draw() {

	brown = color(142,112,60);
	blue = color(121,191,227);
	purple = color(150,124,142);
	pale = color(252,161,142);

	background(255);
	noStroke();

	push();
	translate(500, 0);
	scale(scaleB);
	translate(transX, transY);

	//left bar
	fill(76, 48, 41);
	rect(155, 240, 65, 180);

	//middle bar
	fill(76, 48, 41);
	rect(240, 240, 65, 180);

	//right bar
	fill(76, 48, 41);
	rect(325, 240, 65, 180);
	pop();

drawMicroscope(2);

	/*face*/
	push();
		fill(pale);

		beginShape(); //chin
		curveVertex(38,395);
		curveVertex(38,395);
		curveVertex(52,411);
		curveVertex(150,495);
		curveVertex(188,511);
		curveVertex(218,500);
		curveVertex(235,476);
		curveVertex(243,454);
		curveVertex(243,454);
		endShape();

		beginShape(); //nose
		curveVertex(234,455);
		curveVertex(234,455);
		curveVertex(244,456);
		curveVertex(264,464);
		curveVertex(278,458);
		curveVertex(273,420);
		curveVertex(293,388);
		curveVertex(283,388);
		curveVertex(283,388);
		endShape();

		beginShape(); //forehead
		curveVertex(283,388);
		curveVertex(283,388);
		curveVertex(292,390);
		curveVertex(311,356);
		curveVertex(317,319);
		curveVertex(307,323);
		endShape();

		beginShape();
		endShape();
	pop();

	push();

		fill(brown);

		beginShape();
		curveVertex(34, 463);
		curveVertex(46, 371);
		curveVertex(66, 315);
		curveVertex(93, 242);
		curveVertex(143, 190);
		curveVertex(213, 190);
		curveVertex(285, 235);
		curveVertex(315, 270);
		curveVertex(320, 320);
		curveVertex(300, 460);
		endShape();

	pop();

	push();
		fill(pale);
		quad(150, 348, 176, 347, 200, 446, 104, 419); //between ellipses
		ellipse(120, 349, 60, 60);
		ellipse(214, 348, 76, 84);
		quad(220, 308, 317, 320, 285, 390, 120, 440);
		quad(46, 371, 98, 330, 98, 400, 38.5, 396);
		quad(42, 400, 46, 373, 150, 360, 150, 436);
		quad(175, 386, 287, 387, 220, 475, 140, 429);

  drawHand(2);

	push();
		fill(brown);
		beginShape(); //hair
		curveVertex(389, 251);
		curveVertex(319, 320);
		curveVertex(226, 308);
		curveVertex(186, 231);
		endShape();

		beginShape();
		curveVertex(16, 355);
		curveVertex(46, 370.5);
		curveVertex(80, 353)
		curveVertex(98, 328.5);
		curveVertex(131, 287);
		endShape();

		beginShape(); //shirt
		vertex(0, 440);
		vertex(17,423);
		vertex(114.5, 532);
		vertex(172.5, 634);
		vertex(0, 634);
		endShape();

		beginShape(); //shirt
		curveVertex(17, 423);
		curveVertex(113.7, 531);
		curveVertex(159, 585);
		curveVertex(172, 634);
		curveVertex(172, 634);
		endShape();

		beginShape();	//eye
		curveVertex(229, 370);
		curveVertex(227, 391);
		curveVertex(243, 407);
		curveVertex(256, 413);
		curveVertex(271, 415);
		endShape();

		triangle(227, 391.5, 255, 406, 255.5, 413); //eye
	pop();

	fill(purple);
	ellipse(155,552,8,8); //button

	fill(blue);
	textStyle(BOLD);
	textSize(50);
	text("UN", 26, 81);
	textSize(83);
	text("BIOLOGO", 45, 150);

	translate(500, 0);

	var scaleB = 1;
	var transX = 0;
	var transY = 0;


  //left hand
  beginShape();
  fill(242, 123, 99);
	noStroke();
  vertex(220, 375);
	vertex(240,375);
  curveVertex(240, 375);
  curveVertex(242, 379);
	curveVertex(240, 382);
  vertex(240, 382);
	curveVertex(240, 382);
	curveVertex(242, 386);
	curveVertex(240, 389);
	vertex(240, 389);
	curveVertex(240, 389);
	curveVertex(242, 394);
	curveVertex(240, 397);
	vertex(240,397);
	curveVertex(240, 397);
	curveVertex(242, 401);
	curveVertex(240, 404);
	vertex(240, 404);
	vertex(220, 407);
	curveVertex(220, 407);
	curveVertex(208, 405);
	curveVertex(203, 400);
	vertex(203, 400);
	vertex(203, 390);
	vertex(220, 375);
  vertex(220, 375);
  endShape();

	//right hand
  beginShape();
  fill(242, 123, 99);
	noStroke();
  vertex(325, 375);
	vertex(305,375);
  curveVertex(305, 375);
  curveVertex(303, 379);
	curveVertex(305, 382);
  vertex(305, 382);
	curveVertex(305, 382);
	curveVertex(303, 386);
	curveVertex(305, 389);
	vertex(305, 389);
	curveVertex(305, 389);
	curveVertex(303, 394);
	curveVertex(305, 397);
	vertex(305,397);
	curveVertex(305, 397);
	curveVertex(303, 401);
	curveVertex(305, 404);
	vertex(305, 404);
	vertex(325, 406);
	vertex(325, 406);
	vertex(325, 411);
	vertex(325, 411);
	curveVertex(325, 411);
	curveVertex(333, 403);
	curveVertex(333, 388);
	curveVertex(325, 375);
	vertex(325, 375);
  vertex(325, 375);
  endShape();

  drawHead(1);

  //text
  fill(119, 173, 206);
	noStroke();
	textSize(50);
	textFont("Helvetica");
	text("UN", 37, 80);
	textSize(70);
	text("PRISONNIER", 45, 155);


}
