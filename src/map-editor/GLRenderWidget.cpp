#include "GLRenderWidget.h"

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
