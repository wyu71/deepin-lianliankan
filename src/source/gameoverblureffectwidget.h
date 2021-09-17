/*
* Copyright (C) 2019 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     linxun <linxun@uniontech.com>
*
* Maintainer: zhangdingwen <zhangdingwen@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef GAMEOVERBLUREFFECTWIDGET_H
#define GAMEOVERBLUREFFECTWIDGET_H

#include "global.h"
#include "shadowlabel.h"

#include <DBlurEffectWidget>
#include <DLabel>
#include <QButtonGroup>

DWIDGET_USE_NAMESPACE
class GameoverBlurEffectWidget : public DBlurEffectWidget
{
    Q_OBJECT
public:
    explicit GameoverBlurEffectWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;

private:
    void initUI();
    void initConnect();

public:
    void updateLabel(QString text);

    /**
     * @brief setResult 外部通知游戏结果
     * @param res 游戏结果
     */
    void setResult(bool res);

private slots:
    void onButtonPressed(int id);

signals:
    void backToMainPage();//点击休息一下，返回主界面
    void reGame();//再玩一次
private:
    ShadowLabel *m_tipLabel;//提示语
    QButtonGroup *m_OverBtnGroup;
    bool m_overType = false;//游戏结果
    QPixmap m_pic;
};

#endif // GAMEOVERBLUREFFECTWIDGET_H
