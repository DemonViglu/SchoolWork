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
	/// <param name="a">Ͷ�������</param>
	/// <param name="b">��ý����ĸ���</param>
	/// <param name="c">��ʼ�ʽ�</param>
	Search(float a,float b,float c) {
		Ͷ������� = a;
		��ý����ĸ��� = b;
		��ʼ�ʽ� = c;
		winTime = 0;
	}
	/// <summary>
	/// Ͷ����ٴ���Ϊһ����Ͷ��
	/// </summary>
	/// <param name="times"></param>
	/// <returns>�ô�Ͷ�ʺ����������ж���Ǯ</returns>
	float DoSearch(int times) {
		float tmpMoney = ��ʼ�ʽ�;
		for (int i = 0; i < times; ++i) {
			tmpMoney += ReturnMoney(DealMoney(tmpMoney));
			//cout <<  ��ʼ�ʽ� << endl;
		}
		//cout << winTime << endl;
		//cout << tmpMoney << endl;
		UploadData(tmpMoney);
		MissionEnd();
		return tmpMoney;
	}

	void PrintData() {
		cout << "��һ����" << this->data.data_1 << endl;
		cout << "�ڶ�����" << this->data.data_2 << endl;
		cout << "��������" << this->data.data_3 << endl;
		cout << "��������" << this->data.data_4 << endl;
	}


private:
	float Ͷ�������;
	/// <summary>
	/// Must be from 0 to 1000
	/// </summary>
	int  ��ý����ĸ���;

	float ��ʼ�ʽ�;

	int winTime;

	m_Data data;

	bool ifSuccess() {
		float tmp = rand()*1000/32767;
		if (tmp < ��ý����ĸ���) {
			winTime++;
			return true;
		}
		else {
			return false;
		}
	}

	float ReturnMoney(float Ͷ���ʽ�) {
		if (ifSuccess()) {
			return Ͷ���ʽ� * Ͷ�������;
		}
		else {
			return 0;
		}
	}

	float DealMoney(float &money) {

		//balabala
		//�����money���з��䣬����֮�󷵻ظô����������ѵ�Ǯ
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
		//cout << "ƽ��ʮ���ʵ���У� ���õ� " << sum / 100000 << endl;
		cout <<  sum / 100000 << endl;
	}

	//search->PrintData();


	system("pause");
	return 0;
}