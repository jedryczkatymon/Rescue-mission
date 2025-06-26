#include "gtest/gtest.h"
#include "../include/Smoke.h"
#include <thread>
using namespace std;

SmokeGrenade::SmokeGrenade() : Item("Granat dymny") {}

void SmokeGrenade::applyEffect(Mission &mission)
{
    mission.log("Granat dymny oslepia straznikow w poblizu.");
    mission.applySmokeEffect();
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
}

void Mission::applySmokeEffect()
{
    smokeEffect = 2;
}
class MockMission : public Mission
{
public:
    std::vector<std::string> logs;
    bool smokeEffectApplied = false;

    void log(const std::string &msg)
    {
        logs.push_back(msg);
    }

    void applySmokeEffect()
    {
        smokeEffectApplied = true;
    }
};

TEST(SmokeGrenadeTest, ConstructorSetsName)
{
    SmokeGrenade grenade;
    EXPECT_EQ(grenade.getName(), "Granat dymny");
}

TEST(SmokeGrenadeTest, ApplyEffectLogsMessageAndAppliesSmoke)
{
    SmokeGrenade grenade;
    MockMission mission;

    auto start = std::chrono::steady_clock::now();
    grenade.applyEffect(mission);
    auto end = std::chrono::steady_clock::now();

    ASSERT_FALSE(mission.logs.empty());
    EXPECT_EQ(mission.logs.back(), "Granat dymny oslepia straznikow w poblizu.");

    EXPECT_TRUE(mission.smokeEffectApplied);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    EXPECT_GE(duration, 1200);
}
