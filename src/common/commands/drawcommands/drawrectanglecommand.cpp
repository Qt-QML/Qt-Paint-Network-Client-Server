#include "drawrectanglecommand.h"
#include "../../strategies/drawrectanglestrategy.h"
#include <QDebug>

DrawRectangleCommand::DrawRectangleCommand(QPainter* painter)
    : DrawCommand (painter)
{
    m_drawStrategy = std::make_unique<DrawRectangleStrategy>();
}
