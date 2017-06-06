
function drawTree(treeX, treeHeight) {
	var treeR = random(0, 255);
	var treeG = random(0, 255);
	var treeB = random(0, 255);

	push();
		translate(treeX + 15, 4*height/5);
		noStroke();
		fill(96, 72, 50);
		beginShape();
		vertex(0, 0);
		vertex(10, 0);
		vertex(10, 20);
		vertex(0, 20);
		vertex(0, 0);
		endShape();

		fill(treeR, treeG, treeB);
		beginShape();
		vertex(-11, 0);
		vertex(21, 0);
		vertex(5, -treeHeight);
		vertex(-11, 0);
		endShape();
	pop();

}

function setup() {
	createCanvas(400, 400);
	noLoop();
}

function draw() {
	background(172, 202, 249);

	for(i = 0; i < 13; i++) {
		drawTree(30*i, random(50, 300));
	}

}
