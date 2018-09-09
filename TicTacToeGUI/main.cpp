#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <tictactoegui.h>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

	QGuiApplication app(argc, argv);

	qmlRegisterSingletonType("org.egp.TicTacToeGUI.app", 1, 0, "TictactoeGUI",
							 [](QQmlEngine* engine, QJSEngine* jsEngine)->QJSValue
	{
		Q_UNUSED(jsEngine)
		return engine->newQObject(new TicTacToeGUI);
	});

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
