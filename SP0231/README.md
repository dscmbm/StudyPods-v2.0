<!-- PROJECT SHIELDS -->
[![MIT License][license-shield]][license-url]
[![Discord][discord-shield]][discord-url]

<h1 align="center"> PROPOSAL FOR EXTENSION OF DEADLINE FOR STUDYPOD PROJECTS </h1>
<h3>PROJECT OVERVIEW</h3>
Our project is Blockchain-based E-Polling using Hyperledger Fabric and Flutter as frontend UI. This project uses features of blockchain that are immutability, transparency, and data security. <br>
The project allows the admin to generate a poll and put up a question to be voted for. The user i.e. the voter can see the active polls by the admin and can vote in yes or no based on the agreement to the poll question. The complete voting and poll generation are recorded on the blockchain. A voter can see all the votes he/she had cast in various polls through his/her unique Id to ensure his vote is counted. The data stored in the blockchain is hashed and thus implies nobody can trace back the voter’s identity through any means. 

<h1 align="center"> SP0231 </h1>

This is the folder for team SP0231 participating in StudyPods v2.0 by Developers Student Club MBM.

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-studypods-v2.0">About StudyPods v2.0</a>
    </li>
    <li>
      <a href="#sp0201">SP0231</a>
      <ul>
        <li><a href="#team">Team</a></li>
        <li><a href="#mentor">Mentor</a></li>
      </ul>
    </li>
    <li>
      <a href="#daily-logs">Daily Logs</a>
      <ul>
        <li><a href="#format">Format</a></li>
        <li><a href="#logs">Logs</a></li>
      </ul>
    </li>
    <li><a href="#resources">Resources</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li>
      <a href="#project">Projects</a>
      <ul>
      <!--
        <li><a href="#overview">Overview</a></li>
        <li>
          <a href="#getting-started">Getting Started</a>
          <ul>
            <li><a href="#prerequisites">Prerequisites</a></li>
            <li><a href="#installation">Installation</a></li>
          </ul>  
        </li>
      -->
      <li><a href="#project-1">Project 1</a></li>
      <li><a href="#project-2">Project 2</a></li>
      </ul>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About StudyPods v2.0

Study pods is an initiative taken by DSC MBM to promote peer-to-peer learning among the students with a notion that says “Learn Together, Build Together”.The program is designed to offer participants a good exposure of technology and the technical world. It is an approx one month-long program that connects like-minded participants interested in a particular domain to come together, learn together and then build together. StudyPod mentors assist participants with the roadmap, resources, take weekly updates and solve doubts which cannot be solved by the team members. At the end of the program each StudyPod needs to submit a project or a propsal for a paper that showcases their learnings during the program.

## SP0231

SP0231 is an amazing team built by the efforts of its team members and the support of its mentors

### Team

Prakhar Gupta<br>
Nehal Jaisalmeria<br>
Ravi Thakur<br>


### Mentor

 HARSH GUPTA

## TECHNICAL DETAILS
<li>Hyperledger Fabric is an open-source project, a private blockchain solution designed by IBM, under the umbrella of The Linux Foundation’s Hyperledger Project.</li>
<li>Our Project has four layers, namely, Frontend, Backend, Chaincode, and Blockchain layer.</li>
<li>The frontend Layer is developed using Flutter</li>
<li>The Backend Layer is developed in Nodejs and Express js. It involves creating API endpoints for frontend and Chaincode communication. It also uses Fabric Tools provided by the fabric package for creating Certificate authorities, wallets, etc.</li>
<li>The Chaincode layer is similar to a smart contract and is developed in go language. Its role is to interact with the blockchain, append data according to Project-Logic, provide data reading and writing ability to client or user via frontend and backend layer in accordance to project-logic. </li>

## THE CHAIN-CODE DETAILS
<li>Poll Asset Object having Poll details</li>
<li>Vote Asset Object having Vote details</li>
<li>Poll Creating Function for admin</li>
<li>Checking the existence of a Poll via Poll ID</li>
<li>Reading all votes for each poll Id</li>
<li>Votes by Voter hash</li>
<li>And some more functions to be made</li>


## License

Distributed under the MIT License. See `LICENSE` for more information.


<!-- MARKDOWN LINKS & IMAGES -->
[license-shield]: https://img.shields.io/github/license/dscmbm/StudyPods-v2.0?style=for-the-badge
[license-url]: https://github.com/dscmbm/StudyPods-v2.0/blob/main/LICENSE
[discord-shield]: https://img.shields.io/discord/864499877723504640?style=for-the-badge
[discord-url]: https://discord.gg/fe9s82cE56
