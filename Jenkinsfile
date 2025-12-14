// flask uruchomiony z linii poleceń
// modyfikacja
pipeline {
    agent any
    
    
    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Run with venv') {
            options {
                timeout(time: 1, unit: 'MINUTES') 
                }

            
            steps {
                script {
                        sh '''
                        gcc kod.c
                        '''
                }
            }
        }
    
        
        
    }
    

   
   
}
