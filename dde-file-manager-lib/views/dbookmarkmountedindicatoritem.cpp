/*
 * Copyright (C) 2016 ~ 2018 Deepin Technology Co., Ltd.
 *               2016 ~ 2018 dragondjf
 *
 * Author:     dragondjf<dingjiangfeng@deepin.com>
 *
 * Maintainer: dragondjf<dingjiangfeng@deepin.com>
 *             zccrs<zhangjide@deepin.com>
 *             Tangtong<tangtong@deepin.com>
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

#include "dbookmarkmountedindicatoritem.h"

#include "app/define.h"

#include "deviceinfo/udisklistener.h"

#include "singleton.h"
#include "app/filesignalmanager.h"
#include "dfmevent.h"
#include "windowmanager.h"
#include <QDebug>

DBookmarkMountedIndicatorItem::DBookmarkMountedIndicatorItem(DBookmarkItem *parentItem)
    : DBookmarkItem("MountedIndicator")
    , m_parentItem(parentItem)
{
    init();
}

DBookmarkMountedIndicatorItem::~DBookmarkMountedIndicatorItem()
{

}

void DBookmarkMountedIndicatorItem::init()
{
    setParentItem(m_parentItem);
    setDefaultItem(true);
    setIsMountedIndicator(true);
//    boundImageToHover(":/leftsidebar/images/leftsidebar/unmount_active_16px.svg");
//    boundImageToPress(":/leftsidebar/images/leftsidebar/unmount_normal_16px.svg");
//    boundImageToRelease(":/leftsidebar/images/leftsidebar/unmount_normal_16px.svg");
//    boundImageToChecked(":/leftsidebar/images/leftsidebar/unmount_active_16px.svg");
//    setReleaseBackgroundColor(QColor(Qt::transparent));
//    setPressBackgroundColor(QColor(Qt::transparent));
//    setHoverBackgroundColor(QColor(Qt::transparent));
    setCheckable(true);
    setHoverBackgroundEnable(true);
    setPressBackgroundEnable(true);
    setDraggable(false);
    setBounds(0, 0, 30, 20);
    setPos(QPoint(160, 5));
    hide();
}

void DBookmarkMountedIndicatorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    DBookmarkItem::paint(painter, option, widget);
}

void DBookmarkMountedIndicatorItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setHovered(true);
    update();
}

void DBookmarkMountedIndicatorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return DBookmarkItem::mouseReleaseEvent(event);

    setPress(false);
    setHovered(false);
    deviceListener->unmount(m_parentItem->getDeviceID());
    update();
}

void DBookmarkMountedIndicatorItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    Q_UNUSED(event)
}

