/*
* Copyright (C) 2020 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/

#include <QPainter>
#include <QDebug>
#include <QPointF>
#include <QPainterPath>

#include "widget.h"
#include "ui_widget.h"
#include "setFontSizePage.h"
#include "ui_setFontSizePage.h"
#include "setFontColorPage.h"
#include "ui_setFontColorPage.h"
#include "textEditing.h"
#include "ui_textEditing.h"

#ifndef SHADOW_WIDTH
#define SHADOW_WIDTH 0
#endif

Text_editing::Text_editing(Widget* page,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Text_editing),
    texteditwidget(new TextEditWidget(this))
{
    ui->setupUi(this);
    pNotebook = page;
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setProperty("blurRegion", QRegion(QRect(1, 1, 1, 1)));

    //ui->light_blue_btn->setStyle(new CustomStyle());
    //ui->colorBtn->setCheckable(true);
    texteditwidget->setGeometry(QRect(0, 5, 250, 35));
    texteditwidget->show();

    set_size_page = new Set_font_size_page(this);
    set_size_page->hide();

    set_color_fort_page = new Set_font_color_page(this);
    set_color_fort_page->hide();
    //connect(pNotebook->ui->sort_2_btn,SIGNAL(clicked()),this,SLOT(color_clicked()));
}

Text_editing::~Text_editing()
{
    delete ui;
}

void Text_editing::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QStyleOption opt;
    opt.init(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(opt.palette.color(QPalette::Base));
    painter.setOpacity(0.9);
    // 小三角区域;
    QPolygon trianglePolygon;
    trianglePolygon << QPoint(m_startX, m_triangleHeight + SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startX + m_triangleWidth / 2, SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startX + m_triangleWidth, m_triangleHeight + SHADOW_WIDTH);

    QPainterPath drawPath;

    drawPath.addPolygon(trianglePolygon);
    painter.drawPath(drawPath);
}

void Text_editing::on_light_blue_btn_clicked()
{
    QPointF position = this->pos();
    set_size_page->move(position.x()+183,position.y()+40);
    set_size_page->show();
}

void Text_editing::on_blue_btn_2_clicked()
{
    QPointF position = this->pos();
    set_color_fort_page->move(position.x()+215,position.y()+40);
    set_color_fort_page->show();
}

void Text_editing::color_clicked()
{
    if(sink)
        light_show();
    else
        black_show();
}

void Text_editing::light_show()
{
//    //ui->widget->setStyleSheet(QString::fromUtf8("background:rgb(240,240,240);\n""border-radius:4px;"));
//    ui->BoldBtn->setStyleSheet(QString::fromUtf8("background:rgba(240,240,240,0.9);"));
//    ui->ItalicBtn->setStyleSheet(QString::fromUtf8("background:rgb(240,240,240);"));
//    ui->underlineBtn->setStyleSheet(QString::fromUtf8("background:rgba(240,240,240,0.9);"));
//    ui->StrikeOutResolvedBtn->setStyleSheet(QString::fromUtf8("background:rgba(240,240,240,0.9);"));
//    ui->frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
//    ui->showListBtn->setStyleSheet(QString::fromUtf8("background:rgba(240,240,240,0.9);"));
//    texteditwidget->ui->showNUMList->setStyleSheet(QString::fromUtf8("background:rgba(240,240,240,0.9);"));
//    // ui->blue_btn_2->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 255, 180);\n"));
//    ui->blue_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(167, 167, 167);\n"
//                                                  "border-top-right-radius:4px;\n"
//                                                  "border-top-left-radius:0px;\n"
//                                                  "border-bottom-right-radius:4px;\n"
//                                                  "border-bottom-left-radius:0px;"));
//    ui->light_blue_btn->setStyleSheet(QString::fromUtf8("\n"
//                                                        "background-color: rgb(167, 167, 167);\n"
//                                                        "color: rgba(145, 145, 145, 1);\n"
//                                                        "border-top-left-radius:4px;\n"
//                                                        "border-top-right-radius:0px;\n"
//                                                        "border-bottom-left-radius:4px;\n"
//                                                        "border-bottom-right-radius:0px;\n"));
}

void Text_editing::black_show()
{
//    //ui->widget->setStyleSheet(QString::fromUtf8("background:rgb(19,20,20);\n""border-radius:4px;"));
//    ui->BoldBtn->setStyleSheet(QString::fromUtf8("background:rgba(19,20,20,0.9);"));
//    ui->ItalicBtn->setStyleSheet(QString::fromUtf8("background:rgb(19,20,20);"));
//    ui->underlineBtn->setStyleSheet(QString::fromUtf8("background:rgba(19,20,20,0.9);"));
//    ui->StrikeOutResolvedBtn->setStyleSheet(QString::fromUtf8("background:rgba(19,20,20,0.9);"));
//    ui->frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
//    ui->showListBtn->setStyleSheet(QString::fromUtf8("background:rgba(19,20,20,0.9);"));
//    ui->showNUMList->setStyleSheet(QString::fromUtf8("background:rgba(19,20,20,0.9);"));
//    //ui->blue_btn_2->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 255, 180);\n"));
//    ui->blue_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 67, 67);\n"
//                                                  "border-top-right-radius:4px;\n"
//                                                  "border-top-left-radius:0px;\n"
//                                                  "border-bottom-right-radius:4px;\n"
//                                                  "border-bottom-left-radius:0px;"));
//    ui->light_blue_btn->setStyleSheet(QString::fromUtf8("\n"
//                                                        "background-color: rgb(67, 67, 67);\n"
//                                                        "color: rgba(145, 145, 145, 1);\n"
//                                                        "border-top-left-radius:4px;\n"
//                                                        "border-top-right-radius:0px;\n"
//                                                        "border-bottom-left-radius:4px;\n"
//                                                        "border-bottom-right-radius:0px;\n"));
}


