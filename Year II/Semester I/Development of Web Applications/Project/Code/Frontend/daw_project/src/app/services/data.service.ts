import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { BehaviorSubject, Observable } from 'rxjs';
import { LoginUser } from '../interfaces/login-user';
import { RegisterUser } from '../interfaces/register-user';

@Injectable({
  providedIn: 'root'
})
export class DataService {

  private userSource = new BehaviorSubject({
    email: '',
    password: ''
  });
  public currentUser = this.userSource.asObservable();

  public url = 'https://localhost:5001/api/Account';

  constructor(
    public http: HttpClient
  ) { }

  public changeUserData(user: LoginUser): void {
    this.userSource.next(user);
  }

  public loginUser(loginUser: LoginUser): Observable<any> {
    return this.http.post<any>(`${this.url}/login`, loginUser);

  }

  public registerUser(registerUser: RegisterUser): Observable<RegisterUser> {
    return this.http.post<RegisterUser>(`${this.url}/register`, registerUser);
  }

}
