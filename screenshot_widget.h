#ifndef SCREENSHOT_WIDGET_H
#define SCREENSHOT_WIDGET_H

#include <QWidget>


#include "layer/explore_layer.h"
#include "layer/capturing_layer.h"
#include "layer/captured_layer.h"

#include "helper/math_helper.h"
#include "screenshot_status.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ScreenShotWidget; }
QT_END_NAMESPACE

class ScreenShotWidget : public QWidget
{
    Q_OBJECT

public:
    ScreenShotWidget(QWidget *parent = nullptr);
    ~ScreenShotWidget();
    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
private slots:
    void handleCapturingFinished(bool, QRect*);
    void handleCapturedRect(QRect *, CapturedRectSaveType);

private:
    Ui::ScreenShotWidget *ui;
    QImage screen_pic_;

    ScreenShotStatus status_;
    // 鼠标在捕获截取操作前的移动探索
    ExploreLayer *explore_layer_;
    // 鼠标按下后捕获过程
    CapturingLayer *capturing_layer_;
    // 完成截图区域捕获后的处理
    CapturedLayer *captured_layer_;

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // SCREENSHOT_WIDGET_H
