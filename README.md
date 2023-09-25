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
    <h3 align="center">Raspberry Pi Kernel Module</h3>
    <p align="center">
        SamJSui's Raspberry Pi kernel module repository (internally, named suimodule) is a Linux kernel module that registers a character device driver. The module allocates a kernel buffer to allow reading and writing from userspace.
        <!-- <br />
        <a href="https://github.com/github_username/repo_name"><strong>Explore the docs »</strong></a>
        <br />
        <br />
        <a href="https://github.com/github_username/repo_name">View Demo</a>
        ·
        <a href="https://github.com/github_username/repo_name/issues">Report Bug</a>
        ·
        <a href="https://github.com/github_username/repo_name/issues">Request Feature</a> -->
    </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

**suimodule** is a personal project of mine to better understand how the Linux kernel works and learn how to program systems software, such as drivers and firmware.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

* [![c][c]][c-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

Tested Specifications:
- Raspberry Pi 400 
  - or other devices that run Linux
- Linux Kernel 6.1.21-v8+ 

### Prerequisites

`sudo apt update`

`sudo apt upgrade`

`sudo apt-get install raspberrypi-kernel-headers`
- or [Linux headers](https://www.tecmint.com/install-kernel-headers-in-ubuntu-and-debian/) for your device

### Installation

Clone the repository
- `git clone https://github.com/SamJSui/Pi_Kernel_Module`

Change current directory to the cloned module directory
- `cd Pi_Kernel_Module/suimodule`

Kernel compilation 
- `make`

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Module insertion
- `sudo insmod kmodule.ko`
Check kernel log buffer
- `dmesg`
```
[384.534813] suimodule device number: major=236 minor=0
[384.535215] suimodule successfully loaded
```

### Example file

*Intended to be ran as root*

This file reads the device file from userspace and prints its contents to stdout

```c
/* examples/file_io.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    
    /* Declare variables */
    int fd;
    char buffer[256];

    /* Open file descriptor to device file */
    fd = open("/dev/suidev", O_RDONLY);
    
    /* Copy 256 bytes into buffer */
    read(fd, buffer, 256);

    /* Print buffer */
    printf("%s\n", buffer);
    
    close(fd);
    return 0;
}
```

Compile C file
- `gcc -o file_io file_io.c`

Run the executable
- `./file_io`

`dmesg`
```
[1968.969043] suimodule device file successfully opened
[1968.969236] suimodule device file successfully closed
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] GPIO
- [ ] Interrupt Handling
- [ ] Workqueue

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the Apache License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Email - samuelsui2002 at gmail dot com

Project Link: [https://github.com/SamJSui/Pi_Kernel_Module](https://github.com/SamJSui/Pi_Kernel_Module)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[c]: https://img.shields.io/badge/c-044F88?style=for-the-badge&logo=c&logoColor=white
[c-url]: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html
[cpp]: https://img.shields.io/badge/c++-white?style=for-the-badge&logo=cplusplus&logoColor=044F88
[cpp-url]: https://cplusplus.com/
[CUDA]: https://img.shields.io/badge/CUDA-000000?style=for-the-badge&logo=nvidia&logoColor=76B900
[CUDA-url]: https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html 
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
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
