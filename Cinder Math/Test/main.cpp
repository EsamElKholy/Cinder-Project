#include <iostream>
#include <CinderMath.h>

using namespace Cinder::Math;


int main()
{
	vec2f v2 = vec2f();
	vec3f v31 = vec3f();
	vec3f v32 = vec3f(1, 2, 3);
	vec3f res = vec3f();
	vec4f v4 = vec4f();

	v31 = (v32 + 2.0f);
	Vec3::Cross(v32, v31);
	float x = v32[2];

	mat4f mat4 = mat4f();

	float f = mat4[1][0];


	system("PAUSE");
	return 0;
}
