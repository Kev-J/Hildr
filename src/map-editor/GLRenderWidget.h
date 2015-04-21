#include <QGLWidget>

#include "hildr-map/Map.h"

class GLRenderWidget : public QGLWidget {
	public:
		QGLWidget(QWidget *parent);
		void setMap(Map *map);
		void unsetMap(void);
	protected:
		void initializeGL();
		void resizeGL(int w, int h);
		void paintGL();
	private:
		Map *m_map;
};
