#include "sidebarpluginswidgets.h"

static sidebarPluginsWidgets *global_Plugin_Widgets_instance = nullptr;
sidebarPluginsWidgets::sidebarPluginsWidgets(QWidget *parent) : QWidget(parent)
{
    Q_UNUSED(parent);
    this->setContentsMargins(0,0,0,0);
    this->setFixedSize(400,300);
    this->setStyleSheet("QWidget{background:rgba(255, 255, 0, 0);}");
    m_pBoolStates = true;

    m_pWidgetOutVLayout = new QVBoxLayout();
    m_pWidgetOutVLayout->setContentsMargins(0,0,0,0);

    /* 上半部分 剪贴板 小插件 俩按钮 groupBox初始化布局 */
    initUpGroupBoxButton();

    /* 下半部分 显示插件的界面 */
    initUnGroupBox();

    initLableBackgroundAnimation();
}

/* 返回全局的Widget指针 */
sidebarPluginsWidgets* sidebarPluginsWidgets::getInstancePluinsWidgets()
{
    if (global_Plugin_Widgets_instance == nullptr) {
        global_Plugin_Widgets_instance = new sidebarPluginsWidgets();
    }
    return global_Plugin_Widgets_instance;
}

/* 初始化sidebarPluginsWidgets类 */
void sidebarPluginsWidgets::initPluginsWidgets()
{
    sidebarPluginsWidgets::getInstancePluinsWidgets();
}

/* 上半部分 剪贴板 小插件 俩按钮 groupBox初始化布局 */
void sidebarPluginsWidgets::initUpGroupBoxButton()
{
    m_pButtonWidget = new QWidget(this);
    m_pButtonWidget->setContentsMargins(0,0,0,0);
    m_pButtonWidget->setFixedSize(400, 50);

    m_pGrouBoxUpButtonHLayout = new QHBoxLayout;
    m_pGrouBoxUpButtonHLayout->setContentsMargins(0,5,0,0);

    m_pClipboardButton = new SmallPluginsButton();
    m_pClipboardButton->setText("剪贴板");
    m_pClipboardButton->setObjectName("ClipboardButton");
    m_pClipboardButton->setFixedSize(90,34);
    m_pClipboardButton->setStyleSheet("QPushButton#ClipboardButton{width:90px; \
                                      height:34px; \
                                      background:rgba(61,107,229,0); \
                                      border-radius:4px; \
                                     }");


    m_pSidebarPluginButton = new SmallPluginsButton();
    m_pSidebarPluginButton->setText("小插件");
    m_pSidebarPluginButton->setObjectName("SidebarPluginButton");
    m_pSidebarPluginButton->setFixedSize(90,34);
    m_pSidebarPluginButton->setStyleSheet("QPushButton#SidebarPluginButton{width:90px; \
                                          height:34px; \
                                          background:rgba(61,107,229,0); \
                                          border-radius:4px; \
                                        }");
    m_pBlueBackgroundButton = new QPushButton();
    m_pBlueBackgroundButton->setFixedSize(90, 34);
    m_pBlueBackgroundButton->setObjectName("BlueBackgroundButton");
    m_pBlueBackgroundButton->setStyleSheet("QPushButton#BlueBackgroundButton{background:rgba(61,107,229,1); \
                                border: 0px solid rgba(255,0,0,1);}");
    m_pBlueBackgroundButton->setChecked(false);

    m_pBlueBackgroundButton->setVisible(false);


    QSpacerItem *item1 = new QSpacerItem(10, 20);
    QSpacerItem *item2 = new QSpacerItem(10, 20);
    QSpacerItem *item3 = new QSpacerItem(202,20);
    m_pGrouBoxUpButtonHLayout->addItem(item1);
    m_pGrouBoxUpButtonHLayout->addWidget(m_pClipboardButton);
    m_pGrouBoxUpButtonHLayout->addItem(item2);
    m_pGrouBoxUpButtonHLayout->addWidget(m_pSidebarPluginButton);
    m_pGrouBoxUpButtonHLayout->addItem(item1);
    m_pGrouBoxUpButtonHLayout->addWidget(m_pBlueBackgroundButton);
    m_pGrouBoxUpButtonHLayout->addItem(item3);
    m_pButtonWidget->setLayout(m_pGrouBoxUpButtonHLayout);
    m_pGrouBoxUpButtonHLayout->setSpacing(0);
}

/* 显示插件的界面下半部分 */
void sidebarPluginsWidgets::initUnGroupBox()
{
    /* 剪贴板GroupBox指针 */
    m_pClipboardWidget = new QWidget();
    m_pClipboardWidget->setFixedSize(400, 250);
    m_pClipboardWidget->setContentsMargins(0,0,0,0);

    /* 小插件GroupBox指针 */
    m_pPluginsButtonWidget = new QWidget();
    m_pClipboardWidget->setFixedSize(400, 250);
    m_pPluginsButtonWidget->setContentsMargins(0,0,0,0);

    /* 插件 按钮 */
    m_pNotebookButton = new QToolButton();
    m_pAlarmClockButton = new QToolButton();
    m_pNotebookButton->setObjectName("NotebookButton");
    m_pAlarmClockButton->setObjectName("AlarmClockButton");
    m_pNotebookButton->setFixedSize(90,90);
    m_pAlarmClockButton->setFixedSize(90,90);
    m_pNotebookButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_pAlarmClockButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    /* 笔记本按钮 */
    QIcon NoteBookPng = QIcon::fromTheme("NoteBook", QIcon(KYLIN_NOTEBOOK));
    m_pNotebookButton->setIcon(NoteBookPng);
    m_pNotebookButton->setIconSize(QSize(48,48));
    m_pNotebookButton->setText("笔记本");
    m_pNotebookButton->setStyleSheet("QToolButton#NotebookButton{font-size:14px; \
                                                   font-family:Noto Sans CJK SC; \
                                                   font-weight:400;              \
                                                   color:rgba(255,255,255,1);    \
                                                   line-height:34px;}");

    /* 闹钟按钮 */
    QIcon AlarmPng = QIcon::fromTheme("clock", QIcon(KYLIN_ALARM_CLACK_ICON));
    m_pAlarmClockButton->setIcon(AlarmPng);
    m_pAlarmClockButton->setIconSize(QSize(48,48));
    m_pAlarmClockButton->setText("闹钟");
    m_pAlarmClockButton->setStyleSheet("QToolButton#AlarmClockButton{font-size:14px; \
                                                   font-family:Noto Sans CJK SC; \
                                                   font-weight:400;              \
                                                   color:rgba(255,255,255,1);    \
                                                   line-height:34px;}");

    /* 设置按钮图表 */
    m_pGroupBoxUnSmallPluginsGLayout = new QGridLayout();
    m_pGroupBoxUnSmallPluginsGLayout->setContentsMargins(0,0,0,160);

    m_pPluginsButtonWidget->setLayout(m_pGroupBoxUnSmallPluginsGLayout);

    QSpacerItem *item1 = new QSpacerItem(10, 20);
    QSpacerItem *item2 = new QSpacerItem(10, 20);
    QSpacerItem *item3 = new QSpacerItem(202,20);

    m_pGroupBoxUnSmallPluginsGLayout->addItem(item1,0,0);
    m_pGroupBoxUnSmallPluginsGLayout->addWidget(m_pNotebookButton,0,1);

    m_pGroupBoxUnSmallPluginsGLayout->addItem(item2,0,2);
    m_pGroupBoxUnSmallPluginsGLayout->addWidget(m_pAlarmClockButton,0,3);
    m_pGroupBoxUnSmallPluginsGLayout->addItem(item3,0,4);
    m_pGroupBoxUnSmallPluginsGLayout->setSpacing(0);
}


/* 最后将所有空间加入到Widget中 */
void sidebarPluginsWidgets::AddPluginWidgetInterface()
{
    m_pWidgetOutVLayout->addWidget(m_pButtonWidget);                //加载俩个按钮界面
    m_pWidgetOutVLayout->addWidget(m_pClipboardWidget);             //剪贴板GroupBox
    m_pWidgetOutVLayout->addWidget(m_pPluginsButtonWidget);         //显示小插件的GroupBox
    m_pWidgetOutVLayout->setSpacing(0);
    this->setLayout(m_pWidgetOutVLayout);

    /* 状态机初始化 */
    m_pMachine = new QStateMachine();
    m_pClipBoardState = new QState(m_pMachine);
    m_pSmallPluginsState = new QState(m_pMachine);

    /* 给状态机分配属性 状态一，剪贴板状态 */
    m_pClipBoardState->assignProperty(m_pClipboardWidget, "geometry", QRectF(0, 50, 400, 250));
    m_pClipBoardState->assignProperty(m_pPluginsButtonWidget, "geometry", QRectF(400, 50, 400, 250));

    /* 给状态机分配属性 状态二，小插件页面状态 */
    m_pSmallPluginsState->assignProperty(m_pClipboardWidget, "geometry", QRectF(400, 50, 400, 250));
    m_pSmallPluginsState->assignProperty(m_pPluginsButtonWidget, "geometry", QRectF(0, 50, 400, 250));

    /* 给状态机配置状态转换信号 */
    QAbstractTransition *t1 = m_pClipBoardState->addTransition(m_pSidebarPluginButton, SIGNAL(enterButtonSignal()), m_pSmallPluginsState);
    t1->addAnimation(new QPropertyAnimation(m_pPluginsButtonWidget, "geometry"));


    QAbstractTransition *t2 = m_pSmallPluginsState->addTransition(m_pClipboardButton, SIGNAL(enterButtonSignal()), m_pClipBoardState);
    t2->addAnimation(new QPropertyAnimation(m_pClipboardWidget, "geometry"));

    /* 初始化状态机时所要做的事情 */
    connect(m_pClipBoardState, &QState::propertiesAssigned, this,[=]{
        if (!m_pPluginsButtonWidget->isVisible()) {
            m_pPluginsButtonWidget->setVisible(true);
            m_pSidebarPluginButton->SendSingal();
            qDebug() << "进入小插件界面";
        }
    });
    connect(m_pSmallPluginsState, &QState::propertiesAssigned, this, [=] {
        if (m_pBoolStates) {
            m_pClipboardButton->SendSingal();
            m_pBoolStates = false;
            qDebug() << "进入剪贴板界面";
        }
    });

    /* 进入状态机一需要将小插件按钮的背景设置成空白 */
    connect(m_pClipBoardState, &QState::entered, this, [=](){
        setSmallPluginsButtonBackgroudIsBlank();
        m_pBlueBackgroundButton->setVisible(true);
        m_pAnimationRightLeft->start();
    });

    /* 进入状态机二时将按钮小插件的背景设置成空白 */
    connect(m_pSmallPluginsState, &QState::entered, this, [=](){
        setClipboardButtonBackgroundIsBlank();
        m_pBlueBackgroundButton->setVisible(true);
        m_pAnimationLeftRight->start();
    });

    m_pMachine->setInitialState(m_pClipBoardState);
    m_pMachine->start();
    m_pPluginsButtonWidget->setVisible(false);
}

/* 移动到剪贴板按钮需要修改的界面 */
void sidebarPluginsWidgets::m_pClipBoardStateSlots()
{
    m_pBlueBackgroundButton->setVisible(false);
    setClipboardButtonBackgroundIsBlue();
    setSmallPluginsButtonBackgroudIsBlank();
}

/* 移动到小插件界面按钮需要做的界面修改 */
void sidebarPluginsWidgets::m_pSmallPluginsStateSlots()
{
    m_pBlueBackgroundButton->setVisible(false);
    setClipboardButtonBackgroundIsBlank();
    setSmallPluginsButtonBackgroudIsBlue();
}

/* 新建Lable的动画类 */
void sidebarPluginsWidgets::initLableBackgroundAnimation()
{
    m_pAnimationLeftRight = new QPropertyAnimation(m_pBlueBackgroundButton, "geometry");
    m_pAnimationLeftRight->setDuration(200);
    m_pAnimationLeftRight->setStartValue(QRect(10, 10, 90, 34));
    m_pAnimationLeftRight->setEndValue(QRect(108, 10, 90, 34));
    m_pAnimationRightLeft = new QPropertyAnimation(m_pBlueBackgroundButton, "geometry");
    m_pAnimationRightLeft->setDuration(200);
    m_pAnimationRightLeft->setStartValue(QRect(108, 10, 90, 34));
    m_pAnimationRightLeft->setEndValue(QRect(10, 10, 90, 34));
    connect(m_pAnimationLeftRight, &QPropertyAnimation::finished, this, &sidebarPluginsWidgets::m_pSmallPluginsStateSlots);
    connect(m_pAnimationRightLeft, &QPropertyAnimation::finished, this, &sidebarPluginsWidgets::m_pClipBoardStateSlots);
}

/* 设置侧边栏的按钮背景色为蓝色 */
void sidebarPluginsWidgets::setClipboardButtonBackgroundIsBlue()
{
    m_pClipboardButton->setStyleSheet("QPushButton#ClipboardButton{background:rgba(61,107,229,1);\
                                                                  width:41px; \
                                                                  height:14px; \
                                                                  font-size:14px; \
                                                                  font-family:Noto Sans CJK SC; \
                                                                  font-weight:400; \
                                                                  color:rgba(255,255,255,1); \
                                                                  line-height:34px; \
                                                                  opacity:0.97; \}");
}

void sidebarPluginsWidgets::setSmallPluginsButtonBackgroudIsBlue()
{
    m_pSidebarPluginButton->setStyleSheet("QPushButton#SidebarPluginButton{background:rgba(61,107,229,1);\
                                                                  width:41px; \
                                                                  height:14px; \
                                                                  font-size:14px; \
                                                                  font-family:Noto Sans CJK SC; \
                                                                  font-weight:400; \
                                                                  color:rgba(255,255,255,1); \
                                                                  line-height:34px; \
                                                                  opacity:0.97; \}");
}

void sidebarPluginsWidgets::setClipboardButtonBackgroundIsBlank()
{
    m_pClipboardButton->setStyleSheet("QPushButton#ClipboardButton{background:rgba(61,107,229,0);\
                                                                  width:41px; \
                                                                  height:14px; \
                                                                  font-size:14px; \
                                                                  font-family:Noto Sans CJK SC; \
                                                                  font-weight:400; \
                                                                  color:rgba(255,255,255,1); \
                                                                  line-height:34px; \
                                                                  opacity:0.97; \}");
}

void sidebarPluginsWidgets::setSmallPluginsButtonBackgroudIsBlank()
{
    m_pSidebarPluginButton->setStyleSheet("QPushButton#SidebarPluginButton{background:rgba(61,107,229,0);\
                                                                  width:41px; \
                                                                  height:14px; \
                                                                  font-size:14px; \
                                                                  font-family:Noto Sans CJK SC; \
                                                                  font-weight:400; \
                                                                  color:rgba(255,255,255,1); \
                                                                  line-height:34px; \
                                                                  opacity:0.97; \}");
}

void sidebarPluginsWidgets::setClipboardWidgetSize(int ClipHight)
{
    qDebug() << "设置小剪贴板的界面大小---->" << ClipHight;
    this->setFixedSize(400, ClipHight);
    return;
}
