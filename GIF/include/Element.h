/************************
 * Element class header *
 ************************
 * Represent a          *
 * graphical element on *
 * a Window             *
 ************************/

#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <vector>

// Includes GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"


#ifndef BUFFER_OFFSET

#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

#endif

namespace GIF{

    class Element
    {

        private:

            /**
             *
             */
            std::vector<glm::vec3> m__points;

            /**
             *
             */
            GLuint m__vao;

            /**
             *
             */
            GLuint m__vbo;

            /**
             *
             */
            GIF::Shader* m__shader;

        public:

            /**
             *
             */
            Element();

            /**
             *
             */
            virtual ~Element();

            /**
             *
             */
            virtual void load();

            /**
             *
             */
            virtual void render(glm::mat4 projection = glm::mat4(1.0), glm::mat4 model = glm::mat4(1.0));

            /**
             *
             */
            void addPoint(glm::vec3 point){ m__points.push_back(point); };

            /**
             *
             */
            void removePoint(int i){ m__points.erase(m__points.begin()+i); };

            /**
             *
             */
            void setPoints(std::vector<glm::vec3> points){ m__points = points; };

            /**
             *
             */
            glm::vec3 getPoint(int i){ return m__points[i]; };

            /**
             *
             */
            std::vector<glm::vec3> getPoints(){ return m__points; };

            /**
             *
             */
            GLuint& getVAO(){ return m__vao; };

            /**
             *
             */
            GLuint& getVBO(){ return m__vbo; };

            /**
             *
             */
            void setShader(GIF::Shader* shader){ m__shader = shader; };

            /**
             *
             */
            GIF::Shader* getShader(){ return m__shader; };

            /**
             *
             */
            int getPointsCount();

            /**
             *
             */
            float* getVerticesFloat();

            /**
             *
             */
            void setUVs(std::vector<glm::vec2> uvs) { m__UVs = uvs; };

            /**
             *
             */
            int getUVCount();

            /**
             *
             */
            int getUVsSize();

            /**
             *
             */
            std::vector<glm::vec2> getUVs();

            /**
             *
             */
            float* getUVsFloat();

        private:

            /**
             *
             */
            static float* vec3ToFloat(std::vector<glm::vec3>);

    };

}

#endif
