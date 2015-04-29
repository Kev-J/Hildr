#include <QGLWidget>
#include <SFML/OpenGL.hpp>

#include "hildr-map/Map.h"

class GLRenderWidget : public QGLWidget {
	public:
		GLRenderWidget(QWidget *parent = 0);
		void setMap(Map *map);
		void unsetMap(void);
	protected:
		void initializeGL();
		void resizeGL(int w, int h);
		void paintGL();
	private:
		Map *m_map;
};
