pipeline {
    agent any
    
    stages {
        stage('Kompilacja') {
            steps {
                sh 'gcc -o suma kod.c'
                archiveArtifacts artifacts: 'suma', fingerprint: true
            }
        }
        stage('Upload do FTP') {
            steps {
                ftpPublisher(
                    publishers: ['ALX'],  // Nazwa konfiguracji FTP z ustawień globalnych
                    transfers: [
                        [
                            $class: 'FtpTransfer',
                            sourceFiles: 'suma',
                            remoteDirectory: '${BUILD_NUMBER}/',
                            cleanRemote: false,
                            excludes: '',
                            flatten: true,
                            makeEmptyDirs: false,
                            noDefaultExcludes: false,
                            patternSeparator: '[, ]+'
                        ]
                    ],
                    verbose: true
                )
            }
        }
    }
}
