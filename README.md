<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>







<!-- PROJECT LOGO -->
<br />
<div align="center">
    <!--<img src="images/logo.png" alt="Logo" width="80" height="80">-->
  

  <h1 align="center">DEBRI Shooter</h1>

  
</div>


## Table of Contents
- [About Project](#about-the-project)
- [Demo Video](#demo-video)
- [Screenshots](#screenshots)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## About The Project


This game, built exclusively in C, is a single-stack project that showcases the effective use of data structures and algorithms. The game utilizes a VGA Display connected to hardware platforms such as the DE1-SOC Board. Through efficient Data structures and Algorithms, the game manages the color and timing of each pixel on the VGA screen. Moreover, this game can also be played on a simulator like cpulator, which simulates the DE1-SOC board.

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


<!--## Technologies Used-->

<!--* ![C](data:image/png;base64,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)-->
<!--- C-->
<!--<p align="right">(<a href="#readme-top">back to top</a>)</p>-->



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.


### Installation


1. **Clone the repository**
    ```bash
    git clone https://github.com/aryankes/Debri_Shooter_Game
    ```
2. **Open [CPUlator](https://cpulator.01xz.net/?sys=nios-de1soc)**
    
    ![CPUlator](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/CPUlator.png)

3. **Change the language from nios II to C.**
4. **After Changing the Language upload gameplay.c or just copy its code on the editor**
![Paste the code in Editor](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Paste%20the%20code%20in%20editor.png)
5. **Click on Compile and Load**
6. ![Click Compile and Load to load game](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Click%20on%20Compile%20and%20Load.png)
6. **Click on Continue**: now the VGA screen shows the front screen of the game. You may now proceed to play.
![Clcik on Continue o start game](https://github.com/aryankes/Debri_Shooter_Game/blob/main/Images/Click%20on%20Continue%20the%20Game%20starts%20running.png)
   

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

Distributed under the MIT License. See `license.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Aryan Kesharwani -  aryankesharwani142004@gmail.com

Project Link: [https://github.com/aryankes/Debri_Shooter_Game](https://github.com/aryankes/Debri_Shooter_Game)

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
