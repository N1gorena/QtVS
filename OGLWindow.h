#pragma once
#include <QWINDOW>
#include <QOpenGLFunctions>


class OGLWindow : public QWindow, protected QOpenGLFunctions {
	Q_OBJECT
public:
	OGLWindow(QWindow* parent = 0);
	~OGLWindow();

	void render();

protected:
	void exposeEvent(QExposeEvent *event) override;

private:
	QOpenGLContext* context;

};