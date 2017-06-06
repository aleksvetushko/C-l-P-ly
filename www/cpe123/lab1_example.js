
function setup() {
	createCanvas(400, 400);
}


function draw() {
	background(169, 163, 198);


	//rocks
	fill(91, 84, 72);
	ellipse(30, 310, 120, 80);

	fill(132, 122, 107);
	ellipse(120, 300, 120, 80);

	fill(158, 144, 123);
	ellipse(190, 310, 120, 80);

	fill(124, 112, 93);
	ellipse(340, 310, 120, 80);

	fill(165, 146, 114);
	ellipse(380, 325, 120, 80);

	fill(168, 160, 148);
	ellipse(30, 370, 120, 80);

	fill(137, 118, 88);
	ellipse(110, 369, 120, 80);

	fill(102, 90, 72);
	ellipse(180, 370, 120, 80);

		fill(102, 87, 63);
		ellipse(280, 320, 120, 80);

	fill(196, 189, 178);
	ellipse(260, 370, 120, 80);

	fill(132, 117, 92);
	ellipse(330, 380, 120, 80);

	fill(102, 87, 63);
	ellipse(380, 370, 120, 80);

  //body
  beginShape();
  fill(226, 226, 226);
	noStroke();
  vertex(150, 130);
  vertex(230, 130);
  vertex(260, 260);
  vertex(250, 305);
	vertex(125, 305);
	vertex(100, 260);
	vertex(150, 130);
  endShape();

	//right arm
	beginShape();
	fill(186, 152, 120);
	noStroke();
	vertex(230, 130);
	vertex(285, 115);
	vertex(305, 125);
	vertex(238, 165);
	endShape();

  //right hand
  rotate(-18*PI/180.0);
  fill(234, 227, 220);
	ellipse(255, 204, 45, 20);
	rotate(+18*PI/180.0);

  //left arm
	beginShape();
	fill(186, 152, 120);
	noStroke();
	vertex(150, 130);
	vertex(138, 160);
	vertex(80, 110);
	vertex(90, 95);
	endShape();

  //left hand
	fill(234, 227, 220);
	ellipse(90, 100, 25, 30);

	//head
	fill(204, 195, 144);
	ellipse(190, 90, 110, 120);

	//top of beak
	beginShape();
	fill(239, 178, 167);
	noStroke();
	vertex(225, 75);
	vertex(280, 68);
	vertex(220, 90);
	endShape();

	//mouth
	beginShape();
	fill(214, 38, 38);
	noStroke();
	vertex(220, 90);
	vertex(247, 80);
	vertex(245, 117);
	vertex(223, 112);
	endShape();

	//bottom of beak
	beginShape();
	fill(239, 178, 167);
	noStroke();
	vertex(223, 113);
	vertex(245, 112);
	vertex(263, 120);
	endShape();

	//left leg
	beginShape();
	fill(242, 177, 128);
	noStroke();
	vertex(125, 305);
	vertex(150, 305);
	vertex(100, 340);
	vertex(90, 340);
	endShape();

	//right foot
	beginShape();
	fill(242, 177, 128);
	noStroke();
	vertex(100, 332);
	vertex(105, 360);
	vertex(70, 335);
	endShape();

	//right leg
	beginShape();
	fill(242, 177, 128);
	noStroke();
	vertex(225, 305);
	vertex(250, 305);
	vertex(275, 335);
	vertex(260, 335);
	endShape();

	//right foot
	beginShape();
	fill(242, 177, 128);
	noStroke();
	vertex(267, 330);
	vertex(300, 337);
	vertex(240, 347);
	endShape();

	//eye
	beginShape();
	fill(0);
	noStroke();
	vertex(190, 60);
	vertex(215, 70);
	vertex(195, 78);
	endShape();


}
