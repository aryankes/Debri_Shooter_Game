<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->







<!-- PROJECT LOGO -->
<br />
<div align="center">
    <!--<img src="images/logo.png" alt="Logo" width="80" height="80">-->
  

  <h1 align="center">DEBRI Shooter</h1>

  
</div>


## Table of Contents
- [About Project](#about-the-project)
- [Demo Video](#demo-video)
- [Screenshots](#Screenshots)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
- [Prerequisites](#Prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## About The Project


This game, built exclusively in C, is a single-stack project that showcases the effective use of data structures and algorithms. The game utilizes a VGA Display connected to hardware platforms such as the DE1-SOC Board. Through efficient Data structures and Algorithms, the game manages the color and timing of each pixel on the VGA screen. Moreover, this game can also be played on a simulator like cpulator, which simulates the DE1-SOC board.


<!--<p align="right">(<a href="#readme-top">back to top</a>)</p>-->

## Demo Video

[Watch the live Demo using DE1-SOC Board and VGA Display](https://drive.google.com/file/d/1cM36V7A2YiYvs7pn3hbtUmAAap4LHTOE/view?usp=sharing)

[Watch the Demo using Simulator](https://drive.google.com/file/d/1cM36V7A2YiYvs7pn3hbtUmAAap4LHTOE/view?usp=sharing)

*Click the link to watch the demo video*

## Screenshots
Here are the screenshots of the game displaying on the VGA screen in [CPUlator](https://cpulator.01xz.net/?sys=nios-de1soc)
- **Start Screen**:
![Start Screen](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Start%20Screen.png)
- **Story**: 
![Story Screen](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Story%20Screen.png)
- **Controls**:
![Controls Page](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Controls%20Page.png)
- **ProblemSet**:
![GamePlay](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/GamePlay.png)
- **Moving Left and Right**: 
![Register](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Moving%20Left%20and%20Right.png)
- **Firing Bullets**: 
![Register](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Firing%20Bullets%20to%20destroy%20blocks.png)
- **Game overs as block hits the bottom**:
![Register](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Game%20overs%20as%20Block%20hits%20bottom.png)
- **GameOver**:
![Register](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Game%20Over%20Screen.png)


<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Technologies Used

* ![C](https://drive.google.com/file/d/1vsZmExaxgoz2SYU40Js2SI_tNCcqDJGk/view?usp=sharing)
- C
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.



### Prerequisites

Make sure you have the following software installed on your local machine:
- [Node.js](https://nodejs.org/en/)
- [npm](https://www.npmjs.com/)
- [MongoDB](https://www.mongodb.com/)
- [Docker](https://www.docker.com/) (Optional, for running the judge in a containerized environment)

  

### Installation


1. **Clone the repository**
    ```bash
    git clone https://github.com/aryankes/Online-Judge-Project.git
    cd BackendFrontend
    ```

2. **Install backend dependencies**
    ```bash
    cd backend
    npm install
    ```

3. **Install frontend dependencies**
    ```bash
    cd ../frontend
    npm install
    ```

4. **Install compiler dependencies**
    ```bash
    cd ../compiler
    npm install
    ```

5. **Set up environment variables**
    Create a `.env` file in the `backend` directory and add your configuration details:
    ```
    MONGO_URI=Your_mongo_DB_link
    PORT=5000
    SECRET_KEY =your_secret_key
    salt_rounds=x(no.of rounds)
    CookieSecret=your_secret
    nodemailerPassword=yourSystemEmailPassword
    INSTANCE_IP=yourInstanceIp(If pushing to aws else use "http://localhost")
    ```

6. **Set up environment variables**
    Create a `.env` file in the `frontend` directory and add your configuration details:
    ```env
    VITE_REACT_INSTANCE_IP=yourInstanceIp(If pushing to aws else use "http://localhost")
    ```

7. **Start the backend server**
    ```bash
    cd backend
    nodemon server.js
    ```

8. **Start the frontend server**
    ```bash
    cd ../frontend
    npm run dev
    ```

9. **Start the compiler server**
    ```bash
    cd ../compiler
    nodemon server.js
    ``````

<p align="right">(<a href="#readme-top">back to top</a>)</p>






<!-- ROADMAP -->
## Project Structure

```plaintext
BackendFrontend/
├── backend/
│   ├── controllers/
│   ├── middleware/
│   ├── models/
│   ├── routes/
│   ├── uploads/
│   ├── Dockerfile
│   ├── .env
│   ├── .gitignore
│   ├── server.js
│   └── package.json
├── frontend/
│   ├── public/
│   ├── src/
│   │   ├── assets/
│   │   ├── components/
│   │   ├── pages/
│   │   ├── App.jsx
│   │   ├── App.css
│   │   ├── AuthContext.jsx
│   │   └── main.jsx
│   ├── themes/
│   ├── .env
│   ├── Dockerfile
│   ├── tailwind.config.js
│   ├── vite.config.js
│   └── package.json
├── Compiler/
│   ├── server.js
│   ├── executeCpp.js
│   ├── executeC.js
│   ├── executepy.js
│   ├── generaterFile.js
│   ├── generateInputFile.js
│   └── package.json
└── README.md
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Aryan Kesharwani -  aryankesharwani142004@gmail.com

Project Link: [https://github.com/aryankes/Online-Judge-Project](https://github.com/aryankes/Online-Judge-Project)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
