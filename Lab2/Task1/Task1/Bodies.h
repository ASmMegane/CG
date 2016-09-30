#pragma once

#include <glm/vec3.hpp>
#include <glm/fwd.hpp>
#include <boost/noncopyable.hpp>


class CIdentityCube
{
public:
	CIdentityCube();
    void Update(float deltaTime);
    void Draw()const;

	
	void SetAlpha(float alpha);

private:
	void OutputFaces()const;

	float m_alpha;
};
