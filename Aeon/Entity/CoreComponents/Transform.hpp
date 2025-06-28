#ifndef AEON_ENTITY_CORECOMPONENTS_TRANSFORM_H_
#define AEON_ENTITY_CORECOMPONENTS_TRANSFORM_H_

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace EC
{

struct Transform
{
    Transform(glm::vec3 position) : position(position)
    {
    }

    glm::vec3 position;
    glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    float scale = 1.0f;

    glm::mat4 model;
};

} // namespace EC

#endif
