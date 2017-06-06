
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

function setup() {
	createCanvas(400, 400);
	noLoop();
}

function draw() {
	background(96, 72, 50);

	for(i = 0; i < 10; i++) {
		drawLeaf(random(20, width/2 -20), random(20, height/2 - 20),
		random(.2, 1), random(0, 360));
	}

	for(i = 0; i < 10; i++) {
		drawLeaf(random(width/2 + 20, width - 20), random(20, height/2 - 20),
		random(.2, 1), random(0, 360));
	}

	for(i = 0; i < 10; i++) {
		drawLeaf(random(20, width/2 -20), random(height/2 + 20, height -20),
		random(.2, 1), random(0, 360));
	}

	for(i = 0; i < 10; i++) {
		drawLeaf(random(width/2 + 20, width - 20), random(height/2 + 20, height -20),
		random(.2, 1), random(0, 360));
	}

}
