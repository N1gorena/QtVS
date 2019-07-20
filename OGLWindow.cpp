#include "OGLWindow.h"
#include <QOpenGLPaintDevice>
#include <QPainter>

OGLWindow::OGLWindow(QWindow *parent) : QWindow(parent), m_device(0), context(0) {
	setSurfaceType(QWindow::OpenGLSurface);
	
}

OGLWindow::~OGLWindow()
{
}

void OGLWindow::render()
{
	bool needsInit = false;
	if (!context) {
		context = new QOpenGLContext(this);

		context->setFormat(requestedFormat());
		context->create();
		needsInit = true;
	}

	context->makeCurrent(this);

	if (needsInit) {
		initializeOpenGLFunctions();
	}

	glClearColor(1.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	context->swapBuffers(this);
}

void OGLWindow::exposeEvent(QExposeEvent *event)
{
	Q_UNUSED(event);

	if (isExposed())
		render();
}