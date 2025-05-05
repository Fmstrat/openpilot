#pragma once

#include <QPushButton>

#include "selfdrive/ui/ui.h"

const int btn_size = 192;
const int img_size = (btn_size / 4) * 3;
const int btn_size_lg = btn_size * 1.4;
const int img_size_lg = (btn_size_lg / 4) * 3;

class ExperimentalButton : public QPushButton {
  Q_OBJECT

public:
  explicit ExperimentalButton(QWidget *parent = 0);
  void updateState(const UIState &s);

private:
  void paintEvent(QPaintEvent *event) override;
  void changeMode();

  Params params;
  QPixmap engage_img;
  QPixmap experimental_img;
  bool experimental_mode;
  bool engageable;
};

class EcoButton : public QPushButton {
  Q_OBJECT

public:
  explicit EcoButton(QWidget *parent = 0);
  void updateState(const UIState &s);

private:
  void paintEvent(QPaintEvent *event) override;
  void changeMode();

  Params params;
  QPixmap eco_imgs[3];
  int eco;
};

class AutoFollowButton : public QPushButton {
  Q_OBJECT

public:
  explicit AutoFollowButton(QWidget *parent = 0);
  void updateState(const UIState &s);

private:
  void paintEvent(QPaintEvent *event) override;

  Params params;
  QPixmap imgs[2];
  QPixmap long_control_imgs[2];
  bool auto_follow;
  bool long_control;
  bool cruise_enabled;
};

void drawIcon(QPainter &p, const QPoint &center, const QPixmap &img, const QBrush &bg, float opacity, int bg_btn_size);

void drawImage(QPainter &p, const QPoint &center, const QPixmap &img, float opacity);
