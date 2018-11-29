#include "drawcommand.h"
#include <QDebug>

DrawCommand::DrawCommand(QPainter* painter)
                : m_painter(painter)
{

}

DrawCommand::~DrawCommand()
{
}

void DrawCommand::execute()
{
    qWarning() << "Please provide execution arguments for draw command!";
}

void DrawCommand::execute(const PaintTypes::MouseState &mouseState, bool paintStarted)
{
    if (m_drawStrategy) {
        m_drawStrategy->mouseTouch(mouseState, paintStarted);
        emit updateRequested();
    } else {
        qWarning() << "DrawLineCommand::execute - drawStrategy is null!";
    }
}

void DrawCommand::draw() const
{
    if (m_painter && m_painter->isActive()) {
        m_drawStrategy->drawRequest(m_painter);
    } else {
        qWarning() << "DrawLineCommand::draw - painter is not active!";
    }
}

void DrawCommand::setPainter(QPainter *painter)
{
    m_painter = painter;
}