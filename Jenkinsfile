pipeline {
    agent any
    
    stages {
        stage('Kompilacja') {
            steps {
                sh 'gcc -o suma suma.c'
                archiveArtifacts artifacts: 'suma', fingerprint: true
            }
        }
        stage('Upload do FTP') {
            steps {
                ftpPublisher(
                    alwaysPublishFromMaster: false,
                    continueOnError: false,
                    failOnError: true,
                    masterNodeName: '',
                    paramPublish: [parameterName: ''],
                    publishers: [
                        [
                            $class: 'BapFtpPublisherPlugin',
                            configName: 'ALX',
                            verbose: true,
                            transfers: [
                                [
                                    $class: 'FtpTransfer',
                                    sourceFiles: 'suma',
                                    remoteDirectory: 'uploads/${BUILD_NUMBER}/',
                                    cleanRemote: false,
                                    excludes: '',
                                    flatten: true,
                                    makeEmptyDirs: false,
                                    noDefaultExcludes: false,
                                    patternSeparator: '[, ]+',
                                    asciiMode: false
                                ]
                            ]
                        ]
                    ]
                )
            }
        }
    }
}
