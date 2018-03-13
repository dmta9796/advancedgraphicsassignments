//custom vertex shader with odd result when messing around with wave equations

varying vec2  ModelPos;
varying float LightIntensity;
uniform float time;

void main()
{
    vec2 center=vec2(-0.025,-0.01); // recenter the center of image
    vec2 position=ModelPos; // get postions for recentering
	float posx =position.x+center.x;// recenter x
	float posy =position.y+center.y;// recenter y
    float r=posx*posx+posy*posy; //sqrt not needed as it still looks like waves
    float eq = 20.0*(cos(time)+sin(time))*sin(1.0*posx/r)*sin(3.0*posy/r); // initially wanted membrane of wave equation  
	gl_FragColor=vec4(vec2(eq),0.8,1.0)*LightIntensity; // add light intensity
}

