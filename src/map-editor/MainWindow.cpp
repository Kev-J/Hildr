#include "MainWindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags)
:QMainWindow(parent, flags)
{
    m_glRender = new GLRenderWidget();
    this->setCentralWidget(m_glRender);

    m_map = new Map();
    if (!m_map->load("test-map")) {
        std::cout << "Unable to load map" << std::endl;
        return;
    }

    m_glRender->setMap(m_map);
}

MainWindow::~MainWindow()
{
    m_glRender->unsetMap();
    delete m_map;
    delete m_glRender;
}
