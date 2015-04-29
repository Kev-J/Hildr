#include "GLRenderWidget.h"

#include <iostream>

GLRenderWidget::GLRenderWidget(QWidget *parent)
:QGLWidget(parent), m_map(0)
{
}

void GLRenderWidget::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90.0f, (GLfloat)640/(GLfloat)480, 1.0f, 1000.0f);
    glEnable(GL_DEPTH_TEST);
}

void GLRenderWidget::resizeGL(int w, int h)
{
}

void GLRenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 1.0); // The camera axis cannot be the viewing direction

    if (m_map != 0) {
        m_map->draw();
    }
}

void GLRenderWidget::setMap(Map *map)
{
    m_map = map;
}

void GLRenderWidget::unsetMap()
{
    m_map = 0;
}
