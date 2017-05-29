/**
 * Element class implementation
 */

#include "Element.h"

#include <iostream>
#include <stdlib.h>

#include "GIF.h"

using namespace std;
using namespace glm;
using namespace GIF;

Element::Element(): Controller(), m__clickColor(), m__pos(), m__points(), m__vao(), m__vbo(), m__shader(), m__clickShader(), m__textures(), m__intUniforms()
{

    m__clickColor = vec3(rand() % 256, rand() % 256, rand() % 256);

    m__shader = new Shader("default-120");
    m__shader->load();

    m__clickShader = new Shader("click-default-120");
    m__clickShader->load();

}


Element::~Element()
{

    delete(m__shader);
    delete(m__clickShader);

}


void Element::load()
{


	int sizeVerticesBytes = this->getPointsCount() * 3 * sizeof(float);
	int sizeUVsBytes = this->getUVsSize() * 2 * sizeof(float);

	float* vertices = this->getPointsFloat();
	float* UVs = this->getUVsFloat();

	GLuint& idVAO = this->getVAO();
	GLuint& idVBO = this->getVBO();

	//===============================VBO================================

	// Destruction d'un éventuel ancien VBO
	if (glIsBuffer(idVBO) == GL_TRUE)
		glDeleteBuffers(1, &idVBO);


	// Génération de l'ID
	glGenBuffers(1, &idVBO);


	// Verrouillage du VBO
	glBindBuffer(GL_ARRAY_BUFFER, idVBO);


		// Allocation de la mémoire vidéo
		glBufferData(GL_ARRAY_BUFFER, sizeVerticesBytes + sizeUVsBytes, 0, GL_STATIC_DRAW);

		// Transfert des données
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeVerticesBytes, vertices);
		glBufferSubData(GL_ARRAY_BUFFER, sizeVerticesBytes,  sizeUVsBytes,  UVs);

	// Déverrouillage de l'objet
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//=======================================================================
	// Destruction d'un éventuel ancien VAO

	if (glIsVertexArray(idVAO) == GL_TRUE)
		glDeleteVertexArrays(1, &idVAO);


	// Génération de l'identifiant du VAO
	glGenVertexArrays(1, &idVAO);


	// Verrouillage du VAO
	glBindVertexArray(idVAO);


		// Verrouillage du VBO
		glBindBuffer(GL_ARRAY_BUFFER, idVBO);

			// Accès aux vertices dans la mémoire vidéo

			//Vertices
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
			glEnableVertexAttribArray(0);

			//UVs
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeVerticesBytes));
			glEnableVertexAttribArray(1);

		// Déverrouillage du VBO
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Déverrouillage du VAO
	glBindVertexArray(0);

    /*
	cout << "[Element] load() : Vertices : \n";
	vector<vec3> vecVertices = this->getPoints();
	for (int i = 0; i < this->getPointsCount(); i++)
	{
		cout << vecVertices[i].x << ", " << vecVertices[i].y << ", " << vecVertices[i].z << endl;
	}
	cout << "[Element] load() : UVs : \n";
	for (int i = 0; i < this->getUVCount(); i++)
	{
		cout << m__UVs[i].x << ", " << m__UVs[i].y << endl;
	}
    */

	free(vertices);
	free(UVs);


}


void Element::render(glm::mat4 projection, glm::mat4 model)
{

    Shader* s = m__shader;

    glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glUseProgram(s->getProgramID());

	glBindVertexArray(getVAO());

    //model = glm::translate(model, glm::vec3(m__pos, 0.f));

	s->envoyerMat4("projection", projection);
    s->envoyerMat4("model", model);

    //s->envoyerVec3("clickColor", m__clickColor);

    for(const auto iter : m__intUniforms)
    {

        s->envoyer1I(iter.first, *(iter.second));

    }

    {//Bind textures
        int i = 0;
        for(auto iter : m__textures)
        {

            s->envoyer1I(iter.first, i);

            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, Gif::getTexture(iter.second)->getID());

            i++;

        }
    }

        //Drawcall
	    glDrawArrays(GL_TRIANGLES, 0, getPointsCount());

    {//Unbind Textures
        int i = 0;
        for(auto iter : m__textures)
        {

            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, 0);
            i++;

        }
    }

	glBindVertexArray(0);

	glUseProgram(0);

}


void Element::clickRender(glm::mat4 projection, glm::mat4 model)
{

    glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glUseProgram(m__clickShader->getProgramID());

	glBindVertexArray(getVAO());

    //model = glm::translate(model, glm::vec3(m__pos, 0.f));

	m__clickShader->envoyerMat4("projection", projection);
	m__clickShader->envoyerMat4("model", model);

    m__clickShader->envoyerVec3("clickColor", m__clickColor);

    for(const auto iter : m__intUniforms)
    {

        m__clickShader->envoyer1I(iter.first, *(iter.second));

    }

    {//Bind textures
        int i = 0;
        for(auto iter : m__textures)
        {

            m__clickShader->envoyer1I(iter.first, i);

            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, Gif::getTexture(iter.second)->getID());

            i++;

        }
    }

        //Drawcall
	    glDrawArrays(GL_TRIANGLES, 0, getPointsCount());

    {//Unbind Textures
        int i = 0;
        for(auto iter : m__textures)
        {

            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, 0);
            i++;

        }
    }

	glBindVertexArray(0);

	glUseProgram(0);

}



//=====Vertices=====
int Element::getPointsCount()
{

	return m__points.size();

}


float* Element::getPointsFloat()
{

	return this->vec3ToFloat(m__points);

}


//=====UVs=====
int Element::getUVCount()
{

	return m__UVs.size();

}


int Element::getUVsSize()
{

	return m__UVs.size() * 2 * sizeof(float);

}


float* Element::getUVsFloat()
{

	float* res = (float*)malloc(sizeof(float) * m__UVs.size() * 2);

	for (unsigned int i = 0; i < m__UVs.size(); i++)
	{

		res[i*2] = m__UVs[i].x;
		res[i*2 + 1] = m__UVs[i].y;

	}

	return res;

}


//=====Private=====
float* Element::vec3ToFloat(vector<vec3> tab)
{

	float* res = (float*)malloc(sizeof(float) * tab.size() * 3);

	for (unsigned int i = 0; i < tab.size(); i++)
	{

		res[i*3] = tab[i].x;
		res[i*3 + 1] = tab[i].y;
		res[i*3 + 2] = tab[i].z;

	}

	return res;

}
