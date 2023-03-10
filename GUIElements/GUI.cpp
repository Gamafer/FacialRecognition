#define _CRT_SECURE_NO_DEPRECATE
#define CVUI_IMPLEMENTATION
#include <opencv2/opencv.hpp>
#include "../Face_Recognition/FaceRecognitionSystem.hpp"
#include "GUI.hpp"
#include "cvui.h" 
#include <regex>
#define WINDOW_NAME "Face Recognition System"

// Constructor base, vacío
Gui::Gui() {

}

// Constructor de la interfaz
void Gui::startGUI() {
	//Open Camera:
	cv::VideoCapture cap(0);
	cv::Size cameraSize(500, 350); //Tamaño de la imagen cuando se abre la camara
	cv::Mat camera, cameraShow;
	//To start window:
	cv::Mat frame = cv::Mat(500, 900, CV_8UC3);
	cv::namedWindow(WINDOW_NAME);
	cvui::init(WINDOW_NAME, 20);

	//Read and resize image:
	cv::Mat imagen = cv::imread("lena.jpg");
	cv::Mat cross = cv::imread("lena.jpg");
	cv::Mat IMG1, crossImage, imgCloseMatch;
	cv::Mat userCapture, userCapShow;
	cv::Size size(175, 150); //Tamaño de la imagen cuando se verifica
	cv::Size smallSize(100, 75); //Tamaño de las imagenes cuando se identifica
	cv::Size bigSize(450, 300); //Tamaño de la imagen cuando se quiere agregar un nuevo usuario
	cv::resize(imagen, IMG1, size);
	cv::resize(cross, crossImage, size);
	cv::resize(imagen, imgCloseMatch, smallSize);

	std::string keyboard = "A";

	//Face Recog System:
	FaceRecognitionSystem frs;
	std::string userKey = "";
	std::tuple<Subject, bool> userVeri;
	cv::Mat veriPic, veriPicShow;
	int funcCount = 0;
	std::string tempValues = "";

	std::vector<Subject> userIdenti;

	//Variables for presentation:
	bool clientFound = true;
	bool showHomeScreen = true;
	bool detect121 = false;
	bool detect12N = false;
	bool newUserScreen = false;
	if (!cap.open(0))
	{
		std::cout<<"Webcam Error"<<std::endl;
		return;
	}

	while (true)
	{
		cap >> camera;
	
		
		cv::resize(camera, cameraShow, cameraSize);
		frame = cv::Scalar(35, 31, 20); // Color de fondo

		// ----------------------HomeScreen----------------------------------------------------------------
		if (showHomeScreen) {
			if ((cvui::button(frame, 400, 425, "Verificar")) || cv::waitKey(1) == 118) { //Tecla "v"
				cv::Mat show;
				do
				{   //facedetector.
					cap >> userCapture;
					cvui::rect(frame, 0, 0, 200, 900, 0xF2F7FB);
					cv::resize(userCapture, cameraShow, cameraSize);
					cvui::image(frame, 300, 50, cameraShow);
					cvui::update();
					cv::imshow(WINDOW_NAME, frame);
				}while(!frs.faceRect(userCapture));
				showHomeScreen = false;
				detect121 = true;
				userKey = keyboard;
				funcCount = 0;
			}
			else if ((cvui::button(frame, 600, 425, "Identificar")) || cv::waitKey(1) == 105) { //Tecla "i"
				cv::Mat show;
				do
				{   //facedetector.
					cap >> userCapture;
					cvui::rect(frame, 0, 0, 200, 900, 0xF2F7FB);
					cv::resize(userCapture, cameraShow, cameraSize);
					cvui::image(frame, 300, 50, cameraShow);
					cvui::update();
					cv::imshow(WINDOW_NAME, frame);
				}while(!frs.faceRect(userCapture));
				showHomeScreen = false;
				detect12N = true;
				userKey = keyboard;
				funcCount = 0;
			}
			else if (cvui::button(frame, 10, 20, "Registrar Usuario")) {
				cv::Mat show;
				do
				{   //facedetector.
					cap >> userCapture;
					cvui::rect(frame, 0, 0, 200, 900, 0xF2F7FB);
					cv::resize(userCapture, show, cameraSize);
					cvui::image(frame, 300, 50, show);
					cvui::update();
					cv::imshow(WINDOW_NAME, frame);
				}while(!frs.faceRect(userCapture));
				showHomeScreen = false;
				newUserScreen = true;
				cap >> userCapture;
				funcCount = 0;
			}
			
			//Keyboard: (para ingresar llave):
			if (cvui::button(frame, 10, 100, "1")) {
				keyboard += "1";
			}
			else if (cvui::button(frame, 60, 100, "2")) {
				keyboard += "2";
			}
			else if (cvui::button(frame, 110, 100, "3")) {
				keyboard += "3";
			}
			else if (cvui::button(frame, 10, 150, "4")) {
				keyboard += "4";
			}
			else if (cvui::button(frame, 60, 150, "5")) {
				keyboard += "5";
			}
			else if (cvui::button(frame, 110, 150, "6")) {
				keyboard += "6";
			}
			else if (cvui::button(frame, 10, 200, "7")) {
				keyboard += "7";
			}
			else if (cvui::button(frame, 60, 200, "8")) {
				keyboard += "8";
			}
			else if (cvui::button(frame, 110, 200, "9")) {
				keyboard += "9";
			}
			else if (cvui::button(frame, 60, 250, "0")) {
				keyboard += "0";
			}
			else if (cvui::button(frame, 45, 300, "DELETE")) {
				keyboard = "A";
			}
			if ((cvui::button(frame, 800, 20, "Cerrar")) || cv::waitKey(1) == 27) 
			{
				break;
			}
			cvui::rect(frame, 0, 0, 200, 900, 0xF2F7FB);

			cvui::image(frame, 300, 50, cameraShow);

			cvui::text(frame, 60, 425, keyboard); 
			//muestra letra en intefaz
		}
		
		//-----------------------Screen agregar nuevo usuario ---------------------------------------------
		if (newUserScreen) {
			bool consoleOpen = false;
			std::string matricula = "";
			std::string nombre = "";
			std::string apellido = "";
			std::string carrera = "";
			std::string mail = "";
			char flagBool;
			bool student = true;
			cv::Mat procFace;
			std::string pathFoto = "";

			cv::resize(userCapture, userCapShow, bigSize);
			cvui::image(frame, 50, 50, userCapShow); //Captura de persona a registrar
			cvui::printf(frame, 550, 75, 0.6, 0xF2F7FB, "Quiere agregar a este usuario?");
			cvui::printf(frame, 550, 100, 0.4, 0xF2F7FB, "Llene el formulario en consola");
			cvui::printf(frame, 550, 175, 0.4, 0xFF0000, "LA INTERFAZ SE DETIENE HASTA QUE TERMINE");
			cvui::printf(frame, 550, 200, 0.4, 0xFF0000, "EL REGISTRO EN CONSOLA");
			if (cvui::button(frame, 550, 125, "Empezar")) {
				consoleOpen = true;
			}

			//Formulario en consola:
			if (consoleOpen) {
				std::cout << "Matricula del usuario:" << std::endl;
				do
				{	
				  std::cin >> matricula;
				}while(matricula.at(0)!='A' && matricula.at(0)!='L');

				std::cout << "Nombre del usuario:" << std::endl;
				std::cin >> nombre;
				std::cin >> apellido;
				nombre = nombre + " " + apellido;
				std::cout << "Carrera del usuario:" << std::endl;
				std::cin >> carrera;

				std::cout << "Correo del usuario:" << std::endl;
				const std::regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
				do
				{
					std::cin >> mail;
					
				}while(!std::regex_match(mail, pattern));
				

				std::cout << "Inserta '1' si el usuario es estudiante o '0' si es docente:" << std::endl;
				do
				{
					std::cin >> flagBool;
				} while (flagBool!='0' && flagBool!='1');
				if(flagBool=='0')
				{
					student=false;
				}
				else
				{
					student=true;
				}
				
				pathFoto = "../images/" + matricula + ".jpg";

				cv::imwrite(pathFoto, userCapture);

				frs.addPerson(matricula, nombre, carrera, mail, student, userCapture, pathFoto);

				consoleOpen = false;

				std::cout << "PROCESO COMPLETADO, REGRESE A LA INTERFAZ" << std::endl;
			}

			if (cvui::button(frame, 10, 425, "Regresar")) {
				showHomeScreen = true;
				newUserScreen = false;
				//bandera
			}
		}
		// ----------------------Screen para usuario aceptado 1:N------------------------------------------
		if (detect12N) {
			cv::resize(userCapture, userCapShow, size);
			cvui::image(frame, 50, 100, userCapShow); //Captura del usuario

			if (cvui::button(frame, 10, 425, "Regresar")) {
				showHomeScreen = true;
				detect12N = false;
			}
			cvui::rect(frame, 0, 0, 265, 900, 0xF2F7FB);

			cvui::printf(frame, 50, 75, 0.4, 0xF2F7FB, "Captura del usuario:");
			cvui::printf(frame, 520, 65, 0.4, 0xF2F7FB, "Posibles coincidencias:");

			//Mostrar posibles coincidencias:
			if (funcCount == 0) {
				userIdenti = frs.personIdentification(userCapture);
				funcCount++;
			}
			//std::cout<<"Tamano"<<(userIdenti.at(8))<<std::endl;
			veriPic = cv::imread(userIdenti.at(0).pfp); //modificar codigo
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 300, 100, veriPicShow);
			cvui::printf(frame, 300, 180, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 300, 195, (userIdenti.at(0).name));
			cvui::text(frame, 300, 210, (userIdenti.at(0).id));

			veriPic = cv::imread(userIdenti.at(1).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 540, 100, veriPicShow);
			cvui::printf(frame, 540, 180, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 540, 195, (userIdenti.at(1).name));
			cvui::text(frame, 540, 210, (userIdenti.at(1).id));
			

			veriPic = cv::imread(userIdenti.at(2).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 780, 100, veriPicShow);
			cvui::printf(frame, 780, 180, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 780, 195, (userIdenti.at(2).name));
			cvui::text(frame, 780, 210, (userIdenti.at(2).id));

			veriPic = cv::imread(userIdenti.at(3).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 300, 230, veriPicShow);
			cvui::printf(frame, 300, 310, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 300, 325, (userIdenti.at(3).name));
			cvui::text(frame, 300, 340, (userIdenti.at(3).id));

			veriPic = cv::imread(userIdenti.at(4).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 540, 230, veriPicShow);
			cvui::printf(frame, 540, 310, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 540, 325, (userIdenti.at(4).name));
			cvui::text(frame, 540, 340, (userIdenti.at(4).id));

			veriPic = cv::imread(userIdenti.at(5).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 780, 230, veriPicShow);
			cvui::printf(frame, 780, 310, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 780, 325, (userIdenti.at(5).name));
			cvui::text(frame, 780, 340, (userIdenti.at(5).id));

			veriPic = cv::imread(userIdenti.at(6).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 300, 360, veriPicShow);
			cvui::printf(frame, 300, 440, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 300, 455, (userIdenti.at(6).name));
			cvui::text(frame, 300, 470, (userIdenti.at(6).id));

			veriPic = cv::imread(userIdenti.at(7).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 540, 360, veriPicShow);
			cvui::printf(frame, 540, 440, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 540, 455, (userIdenti.at(7).name));
			cvui::text(frame, 540, 470, (userIdenti.at(7).id));

			veriPic = cv::imread(userIdenti.at(8).pfp);
			cv::resize(veriPic, veriPicShow, smallSize);
			cvui::image(frame, 780, 360, veriPicShow);
			cvui::printf(frame, 780, 440, 0.4, 0xF2F7FB, "Nombre");
			cvui::text(frame, 780, 455, (userIdenti.at(8).name));
			cvui::text(frame, 780, 470, (userIdenti.at(8).id));
		}

		// ----------------------Screen para usuario aceptado 1:1------------------------------------------

		//Constantes (Est�n independientemente de si el usuario es aceptado o rechazado):
		if (detect121) {

			if(userKey.length()==0)
			{
				showHomeScreen = true;
				detect121 = false;
			}
			else
			{	
			//Verificar usuario:
			if (funcCount == 0) {
				userVeri = frs.personVerification(userCapture, userKey);
				funcCount++;
			}

			cvui::printf(frame, 50, 75, 0.4, 0xF2F7FB, "Captura del usuario:");
			cvui::printf(frame, 600, 75, 0.4, 0xF2F7FB, "Foto del Usuario:");
			cv::resize(userCapture, userCapShow, size);
			cvui::image(frame, 50, 100, userCapShow); //Captura del usuario
			if (cvui::button(frame, 10, 425, "Regresar")) {
				showHomeScreen = true;
				detect121 = false;
			}

			cvui::printf(frame, 300, 75, 0.4, 0xF2F7FB, "Datos del Usuario:");
			tempValues = std::get<0>(userVeri).name;
			cvui::text(frame, 300, 100, "Nombre: " + std::get<0>(userVeri).name);
			cvui::text(frame, 300, 125, "Matricula: " + std::get<0>(userVeri).id);
			cvui::text(frame, 300, 150, "Carrera: " + std::get<0>(userVeri).career);
			cvui::text(frame, 300, 175, "Email: " + std::get<0>(userVeri).email);
			if(std::get<0>(userVeri).currStudent)
			{
			 	cvui::printf(frame, 300, 200, 0.4, 0xF2F7FB, "Estudiante");
			}
			else
			{
				 cvui::printf(frame, 300, 200, 0.4, 0xF2F7FB, "Docente");
			}
			
			veriPic = cv::imread(std::get<0>(userVeri).pfp);
			cv::resize(veriPic, veriPicShow, size);
			cvui::image(frame, 600, 100, veriPicShow);//Captura pfp

			//Cuando el usuario es aceptado:
			if (std::get<1>(userVeri)) {
				cvui::printf(frame, 50, 275, 0.8, 0x27EF57, "Aceptado");
			}
			//Cuando el usuario es rechazado:
			else if (std::get<1>(userVeri) == false) {
				cvui::printf(frame, 50, 275, 0.8, 0xef3c27, "Rechazado");
			}
			}
			
		}
				
		cvui::update();
		cv::imshow(WINDOW_NAME, frame);
	}
}