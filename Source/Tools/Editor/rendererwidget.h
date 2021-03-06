#ifndef RENDERERWIDGET_H
#define RENDERERWIDGET_H

#include <Interface/IRHI.h>
#include <QWidget>
#include <RHI/Vulkan/Public/IVkRHI.h>

class RendererWidget : public QWidget
{
  Q_OBJECT
public:
  explicit RendererWidget(QWidget* parent = 0);
  virtual ~RendererWidget();

  void init();
signals:

public:
  virtual void tickRender();

public slots:
  void onTimeOut();

private:
  QTimer* Timer;

protected:
  virtual void resizeEvent(QResizeEvent *event);

private:
  k3d::SharedPtr<k3d::IVkRHI> RHI;
  k3d::DeviceRef Device;
  k3d::SwapChainRef Swapchain;
  k3d::CommandQueueRef Queue;
  k3d::SyncFenceRef FrameFence;
};

#endif // RENDERERWIDGET_H
