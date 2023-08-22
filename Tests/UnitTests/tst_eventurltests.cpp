#include <QtTest>

// add necessary includes here

class EventUrlTests : public QObject
{
    Q_OBJECT

public:
    EventUrlTests();
    ~EventUrlTests();

private slots:
    void test_case1();

};

EventUrlTests::EventUrlTests()
{

}

EventUrlTests::~EventUrlTests()
{

}

void EventUrlTests::test_case1()
{

}

QTEST_APPLESS_MAIN(EventUrlTests)

#include "tst_eventurltests.moc"
