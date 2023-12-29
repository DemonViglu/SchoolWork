#include<iostream>
#include <climits>
#include<math.h>
#include<random>
using namespace std;

struct m_Data {
	int data_1=0;
	int data_2=0;
	int data_3=0;
	int data_4=0;
};

class Search {
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="a">投入产出比</param>
	/// <param name="b">获得奖励的概率</param>
	/// <param name="c">初始资金</param>
	Search(float a,float b,float c) {
		投入产出比 = a;
		获得奖励的概率 = b;
		初始资金 = c;
		winTime = 0;
	}
	/// <summary>
	/// 投入多少次作为一整次投资
	/// </summary>
	/// <param name="times"></param>
	/// <returns>该次投资后你能最终有多少钱</returns>
	float DoSearch(int times) {
		float tmpMoney = 初始资金;
		for (int i = 0; i < times; ++i) {
			tmpMoney += ReturnMoney(DealMoney(tmpMoney));
			//cout <<  初始资金 << endl;
		}
		//cout << winTime << endl;
		//cout << tmpMoney << endl;
		UploadData(tmpMoney);
		MissionEnd();
		return tmpMoney;
	}

	void PrintData() {
		cout << "第一区间" << this->data.data_1 << endl;
		cout << "第二区间" << this->data.data_2 << endl;
		cout << "第三区间" << this->data.data_3 << endl;
		cout << "第四区间" << this->data.data_4 << endl;
	}


private:
	float 投入产出比;
	/// <summary>
	/// Must be from 0 to 1000
	/// </summary>
	int  获得奖励的概率;

	float 初始资金;

	int winTime;

	m_Data data;

	bool ifSuccess() {
		float tmp = rand()*1000/32767;
		if (tmp < 获得奖励的概率) {
			winTime++;
			return true;
		}
		else {
			return false;
		}
	}

	float ReturnMoney(float 投入资金) {
		if (ifSuccess()) {
			return 投入资金 * 投入产出比;
		}
		else {
			return 0;
		}
	}

	float DealMoney(float &money) {

		//balabala
		//这里对money进行分配，分配之后返回该次所决定花费的钱
		money/=2;

		float costMoney=money;
		return costMoney;
	}

	void MissionEnd() {
		winTime = 0;
	}

	void MissionBegin() {

	}

	void UploadData(float tmpMoney) {
		if (tmpMoney < 46) {
			data.data_1++;
		}
		else if (tmpMoney < 100) {
			data.data_2++;
		}
		else if (tmpMoney < 800) {
			data.data_3++;
		}
		else {
			data.data_4++;
		}
	}

};


int main() {
	time_t t;
	srand(time(&t));


	Search *search = new Search(2,500, 100);
	for (int j = 0; j < 100; j++) {
		int sum = 0;
		for (int i = 0; i < 100000; i++) {
			sum += search->DoSearch(j);
		}
		//cout << "平均十万次实验中， 能拿到 " << sum / 100000 << endl;
		cout <<  sum / 100000 << endl;
	}

	//search->PrintData();


	system("pause");
	return 0;
}