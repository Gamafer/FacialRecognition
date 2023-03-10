#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

class Subject {
public:

	std::string id;
	std::string name;
	std::string career;
	std::string email;
	bool currStudent;
	cv::Mat face;
	
	//Para hacer interfaz:
	Subject(std::string matriculaPar, std::string namePar, std::string careerPar, std::string emailPar, bool studentPar, cv::Mat facePar) {
		id = matriculaPar;
		name = namePar;
		career = careerPar;
		email = emailPar;
		currStudent = studentPar;
		face = facePar;
	}

	Subject() {
	
	}
};

//Para cargar en memoria:
class Persistence {
	std::string fileName = "";
	std::map<std::string, Subject> users;
	std::string clientKey = "";
	std::map<std::string, Subject>::iterator itr;


private:
	//Metodo que genera la nueva key, comprobando que no exista:
	std::string generateKey() {
		cv::FileStorage savedCounter(fileName, cv::FileStorage::READ);
		int counter = 0;
		bool search = true;
		std::string saveKey;



		while (search)
		{
			std::string tryKey = "A" + std::to_string(counter);
			cv::FileNode lastKey = savedCounter[tryKey];
			lastKey["Matricula"] >> saveKey;

			if (saveKey.compare("") == 0) {
				search = false;
				clientKey = tryKey;
			}
			counter++;
		}
		return clientKey;
	}

public:
	Persistence(std::string storageFileName) {
		fileName = storageFileName;
		cv::FileStorage fs(fileName, cv::FileStorage::READ);
		bool searchClients = true;
		int keyCounter = 0;
		std::string trykey = "";
		std::string tempMatricula = "";
		std::string tempName = "";
		std::string tempCareer;
		std::string tempEmail = "";
		bool tempStudent = "";
		cv::Mat tempFace;

		cv::FileNode fn = fs.root();

		for (cv::FileNodeIterator fit = fn.begin(); fit != fn.end(); ++fit) {
			//trykey = "A" + std::to_string(keyCounter);
			
			cv::FileNode item = *fit;
			trykey = item.name();

			cv::FileNode fn = fs[trykey];
			fn["Matricula"] >> tempMatricula;
			fn["Name"] >> tempName;
			fn["Career"] >> tempCareer;
			fn["Email"] >> tempEmail;
			fn["Student"] >> tempStudent;
			fn["faceMatrix"] >> tempFace;

			Subject tempClient(tempMatricula, tempName, tempCareer, tempEmail, tempStudent, tempFace);

			if (tempMatricula.compare("") != 0) {
				users.insert(std::pair<std::string, Subject>(trykey, tempClient));
			}
			else {
				searchClients = false;
			}
			keyCounter++;
		}
	}

	void registerClient(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat) {
		Subject newRegister(clientId, clientName, clientCareer, clientEmail, clientStudent, faceMat);
		users.insert(std::pair<std::string, Subject>(generateKey(), newRegister));
	}

	void deleteClient(std::string key) {
		users.erase(key);
	}

	void writeToDisc() {
		cv::FileStorage fs(fileName, cv::FileStorage::WRITE);

		for (itr = users.begin(); itr != users.end(); ++itr) {
			fs << itr->first << "{";
			fs << "Matricula" << itr->second.id;
			fs << "Name" << itr->second.name;
			fs << "Career" << itr->second.career;
			fs << "Email" << itr->second.email;
			fs << "Student" << itr->second.currStudent;
			fs << "faceMatrix" << itr->second.face;
			fs << "}";
		}

		fs.release();
	}

	//GETTERS: Get the atribute searching by key
	cv::Mat getUserFace(std::string userID) {
		return users[userID].face;
	}

	bool getUserIsStudent(std::string userID) {
		return users[userID].currStudent;
	}

	std::string getUserEmail(std::string userID) {
		return users[userID].email;
	}

	std::string getUserCareer(std::string userID) {
		return users[userID].career;
	}

	std::string getUserName(std::string userID) {
		return users[userID].name;
	}

	std::string getUserStudentID(std::string userID) {
		return users[userID].id;
	} 
};
