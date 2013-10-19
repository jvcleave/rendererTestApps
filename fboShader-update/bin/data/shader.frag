precision highp float;
uniform sampler2D   myTexture;
varying vec2        texcoord0;

void main()
{
 gl_FragColor = texture2D(myTexture, texcoord0);
}