var px = [];
var py = [];
var vx = [];
var vy = [];
var ballCr = [];
var ballCg = [];
var ballCb = [];
var numBalls;

function drawLeaf(leafX, leafY, s, rot) {
	var leafR = random(0, 255);
	var leafG = random(0, 255);
	var leafB = random(0, 255);

	push();
		translate(leafX, leafY);
		rotate(radians(rot));
		translate(-leafX, -leafY);
		translate(width/2, height/2);
		fill(leafR, leafG, leafB);
		scale(s);
		noStroke();
		beginShape();
		vertex(1, 0);
		vertex(3, 25);
		vertex(-3, 25);
		vertex(-1, 0);
		vertex(-30, 10);
		vertex(-25, 1);
		vertex(-40, -15);
		vertex(-17, -23);
		vertex(-27, -42);
		vertex(-15, -39);
		vertex(0, -65);
		vertex(15, -39);
		vertex(27, -42);
		vertex(17, -23);
		vertex(40, -15);
		vertex(25, 1);
		vertex(30, 10);
		vertex(1, 0);
		vertex(-1, 0);
		endShape();
	pop();

}

function drawLeafDraw() {
  for(i = 0; i < 10; i++) {
    drawLeaf(random(20, width/2 -20), random(20, height/2 - 20),
    random(0.2, 1), random(0, 360));
  }

  for(i = 0; i < 10; i++) {
    drawLeaf(random(width/2 + 20, width - 20), random(20, height/2 - 20),
    random(0.2, 1), random(0, 360));
  }

  for(i = 0; i < 10; i++) {
    drawLeaf(random(20, width/2 -20), random(height/2 + 20, height -20),
    random(0.2, 1), random(0, 360));
  }

  for(i = 0; i < 10; i++) {
    drawLeaf(random(width/2 + 20, width - 20), random(height/2 + 20, height -20),
    random(0.2, 1), random(0, 360));
  }

}

function setup() {
  createCanvas(400, 400);
  numBalls = 5;
  for (var i=0; i <numBalls; i++) {
    px[i] = random(20, 380);
    py[i] = random(300, 400);
    vx[i] = random(-0.5, 0.5);
    vy[i] = random(-1, -3);
    ballCr[i] = random(0, 255);
    ballCg[i] = random(0, 255);
    ballCb[i] = random(0, 255);
  }

}

function draw() {

  background(12, 34, 56);
  drawLeafDraw();
  for (var i=0; i < numBalls; i++) {
    fill(ballCr[i], ballCg[i], ballCb[i]);
    ellipse(px[i], py[i], 100);
    triangle(px[i]-45, py[i]-20, px[i] - 100, py[i] - 60, px[i] - 40, py[i]- 30);
    fill(0);
    ellipse(px[i]-20, py[i]-20, 10);

    px[i] += vx[i];
    py[i] += vy[i];
  }
}
