
function setup() {
	createCanvas(500, 730);
}

function draw() {
	background(237, 234, 211);

	var scaleB = 1;
	var transX = 0;
	var transY = 0;

  push();
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

  //text
  fill(119, 173, 206);
	noStroke();
	textSize(50);
	textFont("Helvetica");
	text("UN", 37, 80);
	textSize(70);
	text("PRISONNIER", 45, 155);

}
