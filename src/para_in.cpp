#include "ros/ros.h"			//ros/ros.h　ROSに関する基本的なAPIのためのヘッダ
#include "comp_tutorial/adder.h"	//comp_tutrial/adder.h　adder.msgから生成されたメッセージを定義しているヘッダ

int main(int argc, char **argv)
{
	ros::init (argc, argv, "para_in");	//ノード名の初期化「ros::init(argc, argv, "起動時に指定するノード名");」(必須！)
	ros::NodeHandle n;	//ROSシステムとの通信のためのノードハンドルを宣言（必須！）

	//Publisherとしての定義
	// n.advertise<comp_tutorial::adder>("para_input", 1000);
 	// comp_tutorial::adder型のメッセージをpara_inputというトピックへ配信する
	//"1000"はトピックキューの最大値
	ros::Publisher para_pub = n.advertise<comp_tutorial::adder>("para_input", 1000);

	 //1秒間に1つのメッセージをPublishする
	ros::Rate loop_rate(10);

	//comp_tutrial::adder型のオブジェクトを定義
	//adder.msgで定義したa,bはメンバ変数としてアクセスできる
	comp_tutorial::adder msg;

	int count = 0;

	while (ros::ok())	//ctrl + Cが押されるまで繰り返す
	{
		msg.a = count;
		msg.b = count;
		para_pub.publish(msg);
		printf("a = %d B = %d \n", msg.a, msg.b);
		ros::spinOnce();
		loop_rate.sleep();
		count ++;
	}
	return 0;
}
