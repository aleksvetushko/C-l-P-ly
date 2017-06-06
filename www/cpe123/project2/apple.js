function drawApple(x, y, s){
push();
translate(x, y);
scale(s);
fill(255, 8 ,0);
noStroke();
beginShape();
vertex(1.75, -28.7);
bezierVertex(-18.25, -23.7, -43.25, -33.7, -48.25, 6.3);
bezierVertex(-53.25, 46.3, -18.25, 121.3, 11.75, 111.3);
bezierVertex(26.75, 106.3, 21.75, 106.3, 41.75, 111.3);
bezierVertex(81.75, 121.3, 121.75, 22.3, 101.75, -8.7);
bezierVertex(81.75, -38.7, 41.75, -38.7, 1.75, -28.7);
endShape();
fill(58, 95, 11);
beginShape();
vertex(46, -4);
bezierVertex(36, -34, 11, -49, -14, -49);
bezierVertex(-24, -49, -34, -49, -49, -44);
bezierVertex(-34, -34, -24, -19, -4, -19);
bezierVertex(11, -19, 36, -7, 46, -4);
endShape();

beginShape();
vertex(-49, -44);
bezierVertex(-14, -39, 21, -34, 46, -4);
endShape();

beginShape();
vertex(-29, -48.85);
bezierVertex(-25, -47.85, -22, -43, -19, -39);
bezierVertex(-24, -33, -28.5, -34, -35.7, -33.85);
endShape();
beginShape();
vertex(-12, -49);
bezierVertex(-4, -45, -2, -41, 1, -34);
bezierVertex(-2, -30, -8.75, -23.875, -19.75, -22.875);
endShape();
beginShape();
vertex(8, -45);
bezierVertex(13, -41, 17.5, -31.5, 18.5, -26.5);
bezierVertex(13.5, -23.5, 6, -19, -4, -19);
endShape();
beginShape();
vertex(26, -34);
bezierVertex(31.5, -27, 29, -25, 31, -19);
bezierVertex(25, -18, 23, -15, 16, -15);
endShape();
fill(0);
beginShape();
vertex(-8.25, -13.7);
bezierVertex(-3.25, -28.7, 51.75, -33.7, 56.75, -13.7);
bezierVertex(41.75, -8.7, 36.75, -3.7, 21.75, -3.7);
bezierVertex(6.75, -3.7, 1.75, -8.7, -8.25, -13.7);
endShape();

beginShape();
vertex(26.75, -4);
vertex(21.75, -3.7);
bezierVertex(21.75, -28.7, 26.75, -48.7, 31.75, -58.7);
bezierVertex(36.75, -68.7, 38.75, -76.7, 46.75, -68.7);
bezierVertex(51.75, -63.7, 39.9, -65.02, 36.75, -58.7);
bezierVertex(31.75, -48.7, 26.75, -33.7, 26.75, -4);
endShape();

beginShape();
vertex(56.75, -13.7);
bezierVertex(46.75, -8.7, 36.75, -3.7, 21.75, -3.7);
bezierVertex(6.75, -3.7, 1.75, -8.7, -8.25, -13.7);
endShape();
pop();
}